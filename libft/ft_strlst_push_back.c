#include "../includes/libft.h"

t_string *ft_strlst_new(char *string)
{

	t_string *new_str;

	if (!(new_str = (t_string *)malloc(sizeof(t_string))))
		return (NULL);
	new_str->string = ft_strdup(string);
	new_str->next = NULL;
	return (new_str);
}

void ft_strlst_push_back(t_string **begin_list, char *string)
{
	t_string *cur;
	t_string *new;

	new = ft_strlst_new(string);
	cur = NULL;
	if (!*begin_list)
	{
		*begin_list = ft_strlst_new(string);
		return;
	}
	cur = *begin_list;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
}
