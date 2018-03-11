#include "../includes/libft.h"

/*
** makes a string out of a t_string linked list
*/

char *ft_stringify_strlst(t_string *str_list)
{
	t_string *tmp;
	int str_len;

	tmp = str_list;
	str_len = 0;
	while (tmp->next)
	{
		ft_putendl(tmp->string); // TESTING
		str_len = str_len + ft_strlen(tmp->string);
		tmp = tmp->next;
	}
	ft_putnbr(str_len);
	return (NULL); // TESTING
}