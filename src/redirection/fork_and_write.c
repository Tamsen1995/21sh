#include "../../includes/ft_sh.h"

void write_to_process(int *pipe_fd, char *here_doc_string)
{
	int save_fd_out;

	save_fd_out = dup(STDOUT_FILENO);
	close(pipe_fd[0]);
	ft_putstr_fd(here_doc_string, pipe_fd[1]);
	close(pipe_fd[1]);
	dup2(save_fd_out, STDOUT_FILENO);
	close(save_fd_out);
}

/*
** forks the process so that the parent may write from the fd_right into the pipe
** the child process will READ from the pipe and then 
** execute the command with this pipe set up
*/

void fork_and_write(t_shell *shell, int fd_left, char *here_doc_string)
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
	else
	{
		write_to_process(pipe_fd, here_doc_string);
		wpid = waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			wpid = waitpid(pid, &status, WUNTRACED);
	}
}