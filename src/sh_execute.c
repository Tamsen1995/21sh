#include "../includes/ft_sh.h"

/*
** reassigns redirections inside of the cmds array
** so that they may match with the enums 
** defined inside the header
*/

char **assign_redirections(char **cmd)
{
	int i;
	char **ret_cmd;

	i = 0;
	ret_cmd = NULL;
	if (!cmd)
		fatal("Error in (assign_redirections)");
	ret_cmd = ft_alloc_twod_arr(ft_count_arr_size(cmd));
	while (cmd[i])
	{
		if (ft_strcmp(cmd[i], "<") == 0)
			ret_cmd[i] = ft_int_to_str(R_INPUT);
		else if (ft_strcmp(cmd[i], ">") == 0)
			ret_cmd[i] = ft_int_to_str(R_OUTPUT);
		else if (ft_strcmp(cmd[i], ">>") == 0)
			ret_cmd[i] = ft_int_to_str(R_OUTPUT_APPEND);
		else if (ft_strcmp(cmd[i], "|") == 0)
			ret_cmd[i] = ft_int_to_str(R_PIPELINE);
		else if (ft_strcmp(cmd[i], "<&") == 0)
			ret_cmd[i] = ft_int_to_str(R_DUP_INPUT);
		else if (ft_strcmp(cmd[i], ">&") == 0)
			ret_cmd[i] = ft_int_to_str(R_DUP_OUTPUT);
		else if (ft_strcmp(cmd[i], "<<") == 0)
			ret_cmd[i] = ft_int_to_str(R_HERE_DOC);
		else
			ret_cmd[i] = ft_strdup(cmd[i]);
		i++;
	}
	free_twod_arr(cmd);
	return (ret_cmd);
}

/*
** will redirect towards the redirections flow
** , the builtin flow
** or the normal flow
*/

int sh_execute(t_shell *shell)
{

	if (!shell->cmds->args || !shell->cmds->args[0])
		return (1);
	shell->cmds->args = assign_redirections(shell->cmds->args); // WIP
	if (shell->cmds->args &&
		*shell->cmds->args &&
		!exec_redirection(shell) &&
		!exec_builtin(shell))
		return (sh_launch(shell));
	return (1);
}
