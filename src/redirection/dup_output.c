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

/*
** redirects the output of one file into the
** input of another file.
*/

void dup_output(t_shell *shell)
{
	dup_it(shell, STDOUT_FILENO);
}

void dup_input(t_shell *shell)
{
	dup_it(shell, STDIN_FILENO);
}