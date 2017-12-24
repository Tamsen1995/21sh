#include "../../../../includes/ft_sh.h"

/*
** returns a pointer to the 
** buffer element which is found at
** the current tracked cursor position
*/

t_buf       *get_cur_buffer(t_line **line)
{
    t_buf       *ret;
    t_cursor    *tmp_cur;

    ret = NULL;
    tmp_cur = NULL;
    if (!(*line) || !(*line)->first_c || !(*line)->current_c)
        fatal("Error (get_cur_buffer)");
    ret = (*line)->buffer;
    tmp_cur = (*line)->first_c;
    while (ret->next && tmp_cur && tmp_cur->c_ind != (*line)->current_c->c_ind)
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

void          reset_buf_ind(t_line **line)
{
    t_buf   *tmp;
    int     i;

    tmp = NULL;
    i = 0;
    if (!(*line))
        fatal("Error (reset_buf_ind)");
    tmp = (*line)->buffer;
    while (tmp)
    {
        tmp->ind = i;
        tmp = tmp->next;
        i++;
    }
}

/*
** deletes the element before the current cursor position in the buffer
*/

void           del_buf_elem(t_line **line)
{
    t_buf *del;

    del = NULL;
    if (!(*line) || !(*line)->buffer || !(*line)->cursor)
        fatal("Error (del_buf_elem)");
    del = get_cur_buffer(line);
    if (del->ind == (*line)->buffer->ind && !del->prev)
        return ;
    if (del->next)
        del = del->prev;
    if (!del->next)
        del->prev->next = NULL;
    else if (del->prev)
    {
        del->prev->next = del->next;
        del->next->prev = del->prev;
    }
    free_buf_elem(del);
    (*line)->current_c = (*line)->current_c->prev;
    (*line)->last_c = (*line)->last_c->prev;
    reset_buf_ind(line);

}

// TODO insert function
// void        insert_at_cursor();