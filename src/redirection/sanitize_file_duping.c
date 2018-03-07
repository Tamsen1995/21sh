#include "../../includes/ft_sh.h"

//ft_split_str_from_sub(cmd[i], ">&");

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
	// char **redir;
	int i;
	t_string *lst;

	i = 0;
	lst = NULL;
	while (cmd[i])
	{
		// if (ft_strstr(cmd[i], ">&"))
		// {
		// 	/////////////////////
		// 	int k = 0;
		// 	redir = ft_split_str_from_sub(cmd[i], ">&");
		// 	while (redir[k])
		// 	{
		// 		if (ft_strlen(redir[k]) == 0)
		// 		{
		// 			exit (-1);
		// 			// do not put this into the list
		// 		}
		// 		k++;
		// 	}
		// 	////////////
		// }

		// put into list here

		//cmd = sanitize_redirection(cmd);


		i++;
	}

	// at the end turn list into a sanitized array

	exit(-1);

	// TODO : I need something that will seperate a substring from a string and neatly split it into a twod arr

	// if found check for both potential fds before AND after

	// if found then make a new array with these in a seperate array pointer
	return (NULL);
}