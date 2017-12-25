#include "../../../../includes/ft_sh.h"

/*
** returns a pointer to the 
** buffer element which is found at
** the current tracked cursor position
*/

t_buf       *get_cur_buffer(t_line *line)
{
    t_buf       *ret;
    t_cursor    *tmp_cur;

    ret = NULL;
    tmp_cur = NULL;
    if (!line || !line->first_c || !line->current_c)
        fatal("Error (get_cur_buffer)");
    ret = line->buffer;
    tmp_cur = line->first_c;
    while (ret->next && tmp_cur && tmp_cur->c_ind != line->current_c->c_ind)
    {
        ret = ret->next;
        tmp_cur = tmp_cur->next;
    }
    return (ret);
}

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

void          init_buf_ind(t_line *line)
{
    t_buf   *tmp;
    int     i;

    tmp = NULL;
    i = 0;
    if (!line)
        fatal("Error (init_buf_ind)");
    tmp = line->buffer;
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
    t_buf *new_list;

    if (!old_buf || !del_item)
        fatal("Error (make_new_buf)");


    return (NULL);
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
    return (new_buf);
}

// TODO insert function
// void        insert_at_cursor();