#include "../../../../includes/ft_sh.h"

/*
** inserts an element at the cursor position in the buffer
*/

void        put_buf_middle(t_line *line, char *key)
{
    t_buf *cur_buf;
    t_buf *new_buf;

    cur_buf = NULL;
    new_buf = NULL;
    if (!line || !line->buffer || !line->cursor || !key)
        fatal("Error (put_buf_middle)");
    cur_buf = get_cur_buffer(line);
    new_buf = ft_new_buf(key);
    if (cur_buf->prev)
        cur_buf = cur_buf->prev;
    new_buf->next = cur_buf->next;
    new_buf->prev = cur_buf;
    cur_buf->next->prev = new_buf;
    cur_buf->next = new_buf;


}

/*
** returns a copy of the buffer
** with the intended key in the beginning of it
** frees the old buffer
*/

t_buf       *put_buf_at_begin(t_line *line, char *key)
{
    t_buf *tmp;
    t_buf *new_buf;

    tmp = NULL;
    new_buf = NULL;
    if (!line || !line->buffer)
        fatal("Error (put_buf_at_begin)");
    tmp = line->buffer;
	new_buf = ft_new_buf(key);
    while (tmp)
    {
        ft_add_buf(&new_buf, tmp->key);
        tmp = tmp->next;
    }
    free_buffer(line->buffer);
    return (new_buf);
}

/*
** inserts the desired buffer key at
** the current cursor position
*/

void        insert_at_cursor(t_line *line, char *key)
{
    t_buf *tmp_buf;

    tmp_buf = NULL;
    if (!line || !line->cursor || !key)
        fatal("Error (insert_at_cursor)");
    tmp_buf = get_cur_buffer(line);
    if (line->current_c->c_ind == line->last_c->c_ind\
    && !tmp_buf->next)
        ft_add_buf(&line->buffer, key);
    else if (!tmp_buf->prev)
        line->buffer = put_buf_at_begin(line, key);
    else
        put_buf_middle(line, key);
}

/*
** adds a buffer element
** into the buffer
*/

void    insert_buffer(t_line *line, char *key)
{
    t_buf *tmp;

    tmp = NULL;
    if (!line || !key)
        fatal("Error (insert_buffer)");
	if (!line->buffer)
		line->buffer = ft_new_buf(key);
    else
        insert_at_cursor(line, key);
    line->current_c = line->current_c->next;
    line->last_c = line->last_c->next;
    init_buf_ind(line->buffer);
}
