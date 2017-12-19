#include "../../../includes/ft_sh.h"

/*
** allocates a new cursor list element
*/

t_cursor      *ft_new_cur(void)
{
    t_cursor *new;

    if (!(new = (t_cursor *)malloc(sizeof(t_cursor))))
        fatal("Error: could not allocate env var list elem in ft_new_env");
    new->next = NULL;
    new->prev = NULL;
    new->cursor = FALSE;
    return (new);
}

/*
** pushes a cursor element to the end of a list
*/

void		ft_add_cursor(t_cursor **begin_list)
{
    t_cursor *tmp;

    tmp = NULL;
	if (!*begin_list)
	{
		*begin_list = ft_new_cur();
		return ;
	}
    else
    {
        tmp = *begin_list;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = ft_new_cur();
        tmp->next->prev = tmp;
    }
}

/*
** returns a linked list which will be used to keep track
** of the cursor
** each list element represents a potential cursor position
** the length of the list will be that of the columns 
** within the temrinal window
*/

t_cursor       *init_cursor(int win_size)
{
    int i;
    t_cursor *cur_list;

    i = 0;
    cur_list = NULL;
    if (!win_size)
        fatal("Error (init_cursor)");
    while (i < win_size)
    {
        ft_add_cursor(&cur_list);
        i++;
    }
    return (cur_list);
}
