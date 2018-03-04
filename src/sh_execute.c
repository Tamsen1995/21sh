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
	if (shell->cmds->args && *shell->cmds->args && !exec_redirection(shell))
		return (sh_launch(shell));

	exit(-1); // TESTING

	return (1); // TESTING
	// if (check_builtins(cmd[0]) == TRUE ||
	//     check_builtin_path(shell) == TRUE)
	//     return (exec_builtin(shell));

	// return (sh_launch(envv, shell));
}
