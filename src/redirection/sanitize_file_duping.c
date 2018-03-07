#include "../../includes/ft_sh.h"

//ft_split_str_from_sub(cmd[i], ">&");

void add_sanitation_to_list(t_string **begin_lst)
{
	*begin_lst = NULL; // TESTING
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
	int i;
	char **redir;
	t_string *lst;

	i = 0;
	lst = NULL;
	while (cmd[i])
	{
		if (ft_strstr(cmd[i], ">&"))
		{
			redir = ft_split_str_from_sub(cmd[i], ">&"); // makes a sanitized twod arr
			add_sanitation_to_list(&lst); // adds the sanitized twod arr to the list
		}
		else
			ft_strlst_push_back(&lst, cmd[i]); // adds the normal array elements to the list
		i++;
	}

	// at the end turn list into a sanitized array

	exit(-1);

	// TODO : I need something that will seperate a substring from a string and neatly split it into a twod arr

	// if found check for both potential fds before AND after

	// if found then make a new array with these in a seperate array pointer
	return (NULL);
}