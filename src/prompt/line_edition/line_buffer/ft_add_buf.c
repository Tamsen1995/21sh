#include "../../../../includes/ft_sh.h"

/*
** allocates a new buffer list element
*/

t_buf      *ft_new_buf(char *key)
{
    t_buf *new;

    if (!(new = (t_buf *)malloc(sizeof(t_buf))))
        fatal("Error: could not allocate env var list elem in ft_new_env");
    new->next = NULL;
    new->prev = NULL;
    new->key = NULL;
    new->ind = 0;
    new->key = ft_strdup(key);
    return (new);
}

/* 
** iterates to the end of the buf key list
** and then adds the value to it
*/

void		ft_add_buf(t_buf **begin_list, char *key)
{
    t_buf *tmp;

    tmp = NULL;
	if (!*begin_list)
	{
		*begin_list = ft_new_buf(key);
		return ;
	}
    else
    {
        tmp = *begin_list;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = ft_new_buf(key);
        tmp->next->prev = tmp;
    }
}