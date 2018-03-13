#include "../../includes/ft_sh.h"

void add_sanitation_to_list(t_string **begin_lst, char *string, char *substr)
{
	int i;
	char **redir;

	i = 0;
	redir = ft_split_str_from_sub(string, substr); // makes a sanitized twod arr
	while (redir[i])
	{
		if (ft_strlen(redir[i]) > 0)
			ft_strlst_push_back(begin_lst, redir[i]); // adds the normal array elements to the list
		i++;
	}
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
	t_string *lst;
	char **ret;

	i = 0;
	lst = NULL;
	while (cmd[i])
	{
		if (ft_strstr(cmd[i], ">&"))
			add_sanitation_to_list(&lst, cmd[i], ">&"); // adds the sanitized twod arr to the list
		else if (ft_strstr(cmd[i], "<&"))
			add_sanitation_to_list(&lst, cmd[i], "<&"); // adds the sanitized twod arr to the list
		else if (ft_strstr(cmd[i], "<<"))
			add_sanitation_to_list(&lst, cmd[i], "<<");
		else
			ft_strlst_push_back(&lst, cmd[i]); // adds the normal array elements to the list
		i++;
	}
	ret = ft_list_to_arr(lst);
	free_twod_arr(cmd);
	return (ret);
}