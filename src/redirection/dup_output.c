#include "../../includes/ft_sh.h"

void dup_it(t_shell *shell, int default_left_fd)
{
	int fd_left;
	int fd_right;
	char **cmd;
	int i;

	i = 0;
	cmd = shell->cmds->args;
	fd_left = -1;
	fd_right = -1;
	while (cmd[i] && !ft_strchr(cmd[i], R_DUP_OUTPUT))
		i++;
	ft_putendl(cmd[i]);
	default_left_fd = 0;
	exit(-1);

}

/*
** redirects the output of one file into the
** input of another file.
*/

void dup_output(t_shell *shell)
{
	dup_it(shell, STDOUT_FILENO);
	exit(-1);

	// get to the redirection

	// check if there are any file descriptors that want to be redirected
	// if no then make the standard output the file descriptor to be redirected.

	//
}
