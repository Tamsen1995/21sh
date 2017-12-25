#include "../../../../includes/ft_sh.h"

/*
** inserts the desired buffer key at
** the current cursor position
*/

void    insert_buffer(t_line *line, char *key)
{
    t_buf *tmp;

    tmp = NULL;
    if (!line || !key)
        fatal("Error (insert_buffer)");
	if (!line->buffer)
	{
		line->buffer = ft_new_buf(key);
		return ;
	}

    // line->current_c = line->current_c->next;
    // line->last_c = line->last_c->next;
    // init_buf_ind(line->buffer);
}

/*
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
*/