#include "../includes/libft.h"

/*
** makes a string out of a t_string linked list
*/

char *ft_stringify_strlst(t_string *str_list)
{
	t_string *tmp;
	char *ret_string;
	char *tmp_string;
	int str_len;

	tmp = str_list;
	str_len = 0;
	while (tmp->next)
	{
		str_len = str_len + ft_strlen(tmp->string);
		tmp = tmp->next;
	}
	ret_string = ft_strnew(str_len + 5);
	tmp = str_list;
	while (tmp->next)
	{
		ret_string = ft_strcat(ret_string, tmp->string);
		tmp = tmp->next;
	}
	return (ret_string);
}