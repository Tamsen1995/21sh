#include "../../includes/ft_sh.h"

char **remove_redir_from_array(char **cmd, int redir_index)
{
	char **copy;

	copy = ft_copy_twod_arr(cmd);
	if (copy[redir_index - 1] && ((get_fd(cmd[redir_index - 1])) != -1))
		cmd = ft_arrdelone(cmd, copy[redir_index - 1]);
	if (copy[redir_index])
		cmd = ft_arrdelone(cmd, copy[redir_index]);
	if (copy[redir_index + 1])
		cmd = ft_arrdelone(cmd, copy[redir_index + 1]);
	free_twod_arr(copy);
	return (cmd);
}

void simply_dup_it(t_shell *shell, int fd_left, int fd_right)
{
	int fd_save;

	fd_save = dup(fd_left);
	close(fd_left); // not sure about this
	dup2(fd_right, fd_left);
	close(fd_right);
	sh_execute(shell);
	dup2(fd_save, fd_left);
	close(fd_save);
	
}

/*
** discern the left file descriptor as well as the 
** right one
** replace the left with the right one
*/

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
	if ((fd_left = get_fd(cmd[i - 1])) == -1)
		fd_left = default_left_fd;
	if ((fd_right = get_fd(cmd[i + 1])) == -1 && ((fd_right = open(cmd[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0664)) == -1))
		fatal("(THIS SHOULD SIMPLY RETURN, MAYBE FREE SOME STUFF?) No fd was found in (dup_it) change this error message later as it exits the program instead of simply throwing and error");
	shell->cmds->args = remove_redir_from_array(cmd, i);
	simply_dup_it(shell, fd_left, fd_right);
}

/*
** redirects the output of one file into the
** input of another file.
*/

void dup_output(t_shell *shell)
{
	dup_it(shell, STDOUT_FILENO);
}
