#include "../../includes/ft_sh.h"

int get_fd(char *s)
{
	int fd;

	if (!s)
		return (-1);
	while (*s && !ft_isdigit(*s) && *s != '-')
		s++;
	if (!*s)
		return (-1);
	fd = ft_atoi(s);
	return (fcntl(fd, F_GETFD) ? -1 : fd);
}

/*
** finds the fd to be replaced 
** finds the fd that is supposed to replace
** stores these in two seperate variables (fd_left and fd_right)
** deletes the redirection symbol as well as the redirection file from the cmds array
*/

void  do_redirect(t_shell *shell, enum e_replacement c, int o_flag, void (*do_stuff_with_cmd_and_fd_now)(t_shell *, int, int))
{
	int i;
	char *tmp;
	int fd_left;
	int fd_right;

	i = 0;
	while (shell->cmds->args[i] && !(tmp = ft_strchr(shell->cmds->args[i], c)))
		i++;
	if ((ft_strcmp(shell->cmds->args[i], tmp) == 0) || (fd_left = get_fd(shell->cmds->args[i])) == -1)
		fd_left = c == R_INPUT ? STDIN_FILENO : STDOUT_FILENO;
	if ((fd_right = open(shell->cmds->args[i + 1], o_flag, 0664)) == -1) // getting the fd of the file that is supposed to replace the initial fd
		fatal("Could not get fd in (do_redirect)");
	if (tmp) // if the redirection sign is still in tmp
	{
		tmp = ft_strdup(tmp);
		shell->cmds->args = ft_arrdelone(shell->cmds->args, shell->cmds->args[i + 1]); // deletes the the file whose fd is now inside of fd_right
		shell->cmds->args = ft_arrdelone(shell->cmds->args, tmp); // rid the shell->cmds->argss array of the redirection sign
	}
	do_stuff_with_cmd_and_fd_now(shell, fd_left, fd_right);
}
