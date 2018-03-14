#include "../../../../includes/ft_sh.h"


/*
** frees a buf element
*/

void            free_buf_elem(t_buf *buf_elem)
{
    ft_strfree(buf_elem->key);
    free(buf_elem);
    buf_elem = NULL;
}

/*
** everytime a buffer element is removed the buffer indexes need
** to be reset.
*/

void          init_buf_ind(t_buf    *buffer)
{
    t_buf   *tmp;
    int     i;

    tmp = NULL;
    i = 0;
    tmp = buffer;
    while (tmp)
    {
        tmp->ind = i;
        tmp = tmp->next;
        i++;
    }
}

/*
** returns a copy of the old buffer
** without the del_item elem
*/


t_buf           *make_new_buf(t_buf *old_buf, t_buf *del_item)
{
    t_buf *tmp;
    t_buf *new_buf;

    tmp = NULL;
    new_buf = NULL;
    if (!old_buf || !del_item)
        fatal("Error (make_new_buf)");
    tmp = old_buf;
    while (tmp)
    {
        if (tmp->ind != del_item->ind)
            ft_add_buf(&new_buf, tmp->key);
        tmp = tmp->next;
    }
    if (new_buf)
        init_buf_ind(new_buf);
    return (new_buf);
}

/*
** selects the element before the current buffer position
** then makes a new list without the selected item
*/

t_buf           *del_buf_elem(t_line *line)
{
    t_buf *del;
    t_buf *new_buf;

    new_buf = NULL;
    if (line->current_c->c_ind == line->first_c->c_ind) // if the cursor is on the first position
        return (line->buffer);
    del = get_cur_buffer(line);
    if (del->next) // if it's not the last item
        del = del->prev;
    new_buf = make_new_buf(line->buffer, del);
    line->current_c = line->current_c->prev;
    line->last_c = line->last_c->prev;
    free_buffer(line->buffer);
    return (new_buf);
}
