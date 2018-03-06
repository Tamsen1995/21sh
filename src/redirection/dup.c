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