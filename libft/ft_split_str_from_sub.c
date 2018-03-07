#include "../includes/libft.h"

t_bool error_check(char *string, char *substring)
{
	if (!string || !substring)
		return (FALSE);
	return (TRUE);
}

/*
** will seperate a substring from a string and neatly split 
** the string into a twod arr
*/

char **ft_split_str_from_sub(char *string, char *substring)
{
	char **ret;
	int i;
	char *tmp;

	i = 0;
	ret = ft_alloc_twod_arr_with_mem(3, ft_strlen(string));
	if (!error_check(string, substring))
		fatal("ERROR IN : (ft_split_str_from_sub)");
	tmp = string;
	while (*string && ft_strncmp(string, substring, ft_strlen(substring)) != 0)
		ret[0][i++] = *(string++);
	i = 0;
	while (*string && ft_strncmp(string, substring, ft_strlen(substring)) == 0)
		ret[1][i++] = *(string++);
	ret[1][i++] = *(string++);
	i = 0;
	while (*string)
		ret[2][i++] = *(string++);
	return (ret);
}
