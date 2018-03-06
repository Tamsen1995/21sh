#include "../../includes/ft_sh.h"

void dup_exec(t_shell *shell, int *pipe_fd, int fd_left)
{
	int save_fd;

	save_fd = dup(fd_left);
	close(pipe_fd[fd_left == STDOUT_FILENO ? 0 : 1]); // closing write end because this process will only read from the pipe
	dup2(pipe_fd[fd_left == STDOUT_FILENO ? 1 : 0], fd_left);
	close(pipe_fd[fd_left == STDOUT_FILENO ? 1 : 0]);

	sh_execute(shell);
	// execute command recursively

	// make the fd_left into the save_fd (its initial value) again
	dup2(save_fd, fd_left);
	close(save_fd);
	fd_left == STDOUT_FILENO ? (void)wait(NULL) : exit(EXIT_SUCCESS);
}

void write_to_pipe(int *pipe_fd, int fd_right)
{
	int			save_fd_out;
	char		buf[BUFF_SIZE];
	ssize_t		ret;

	save_fd_out = dup(STDOUT_FILENO);
	close(pipe_fd[0]);
	while ((ret = read(fd_right, buf, BUFF_SIZE)) > 0)
	{
	//	ft_putendl(buf); // TESTING
		write(pipe_fd[1], buf, (size_t)ret);
	}
	close(pipe_fd[1]);
	dup2(save_fd_out, STDOUT_FILENO);
	close(save_fd_out);
	close(fd_right);


	wait(NULL);
}

/*
** forks the process so that the parent may write from the fd_right into the pipe
** the child process will READ from the pipe and then 
** execute the command with this pipe set up
*/

static void fork_that(t_shell *shell, int fd_left, int fd_right)
{
	pid_t pid;
	pid_t wpid;
	int status;
	int pipe_fd[2];

	if (pipe(pipe_fd) < 0)
		fatal("Could not open pipe in (fork_that)");
	pid = fork();
	if (pid == 0)
		dup_exec(shell, pipe_fd, fd_left);
	else if (pid < 0)
		fatal("Child procress could not be created (sh_launch)");
	else // this is the parent process which will have to write
	{
		write_to_pipe(pipe_fd, fd_right);
		wpid = waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			wpid = waitpid(pid, &status, WUNTRACED);
	}
}

// calls the do_redirect(cmd, R_INPUT, O_RDONLY, fork_that); function
// with the R_INPUT enum, some flags for the rights of the
void input_redirect(t_shell *shell)
{
	do_redirect(shell, R_INPUT, O_RDONLY, fork_that);
}
