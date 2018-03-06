#include "../../includes/ft_sh.h"

/*
** will execute the given command with a replaced file descriptor
*/

void dup_fd(t_shell *shell, int fd_left, int fd_right)
{
	int fd_save;

	fd_save = dup(fd_left);
	dup2(fd_right, fd_left);
	sh_execute(shell);
	dup2(fd_save, fd_left);
	close(fd_right);
	close(fd_save);
}

void output_redirect(t_shell *shell)
{
	do_redirect(shell, R_OUTPUT, O_WRONLY | O_CREAT | O_TRUNC, dup_fd);
}
