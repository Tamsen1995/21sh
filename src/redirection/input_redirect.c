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

	// close the save fd

	// make the process wait or exit

	// 	exec_cmd(cmd);
	// dup2(save_fd, fd_left);
	// close(save_fd);
	// fd_left == STDOUT_FILENO ? (void)wait(NULL) : exit(EXIT_SUCCESS);

	// closes the fd left

	//
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

	fd_right = 42; // TESTING
	if (pipe(pipe_fd) < 0)
		fatal("Could not open pipe in (fork_that)");
	pid = fork();
	if (pid == 0)
	{
		dup_exec(shell, pipe_fd, fd_left);
		// replaces the fd_left with the either read or write end of the pipe depending
		// on what needs replacing, then executes the command with the modified
		// fds
		// the write to pipe function below writes to the other end of the pipe.
	}
	else if (pid < 0)
		fatal("Child procress could not be created (sh_launch)");
	else
	{
		// write to the pipe with the fd_right
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
