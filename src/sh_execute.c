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
		else if (ft_strcmp(cmd[i], "<&") == 0) // look for the substring of <&
			ret_cmd[i] = ft_int_to_str(R_DUP_INPUT);
		else if (ft_strcmp(cmd[i], ">&") == 0) // look for the substring of >&
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
** in the case of a shorthand fd redirection ">&" or "<&"
** there could be fds right after, and before the redirections.
** if this is the case we need to split up the array further so that these fds
** will not interfere with the normal execution flow
** and the flow may execute normally
*/

char **sanitize_file_duping(char **cmd)
{
	// char **ret;
	
	int i;

	i = 0;
	while (cmd[i])
	{
		if (ft_strstr(cmd[i], ">&"))
			ft_split_str_from_sub(cmd[i], ">&");
		i++;
	}

	exit(-1);

	// TODO : I need something that will seperate a substring from a string and neatly split it into a twod arr

	// if found check for both potential fds before AND after

	// if found then make a new array with these in a seperate array pointer
	return (NULL);
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
	shell->cmds->args = sanitize_file_duping(shell->cmds->args);
	shell->cmds->args = assign_redirections(shell->cmds->args); // WIP
	if (shell->cmds->args &&
		*shell->cmds->args &&
		!exec_redirection(shell) &&
		!exec_builtin(shell))
		return (sh_launch(shell));
	return (1);
}
