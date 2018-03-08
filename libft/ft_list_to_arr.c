#include "../includes/libft.h"

/*
** turns a list of strings into
** a twod array
*/

char **ft_list_to_arr(t_string *lst)
{
	char **ret;
	int len;
	t_string *tmp;

	tmp = lst;
	len = 0;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	ret = ft_alloc_twod_arr(len);
	tmp = lst;
	len = 0;
	while (tmp)
	{
		ret[len] = ft_strdup(tmp->string);
		len++;
		tmp = tmp->next;
	}
	return (ret);
}
