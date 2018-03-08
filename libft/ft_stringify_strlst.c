#include "../includes/libft.h"

/*
** makes a string out of a t_string linked list
*/

char *ft_stringify_strlst(t_string *str_list)
{
	t_string *tmp;

	tmp = str_list;
	while (tmp)
	{
		tmp = tmp->next;
	}

}