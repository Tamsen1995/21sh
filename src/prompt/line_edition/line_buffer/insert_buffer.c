#include "../../../../includes/ft_sh.h"

/*
** inserts the desired buffer key at
** the current cursor position
*/

void        insert_at_cursor(t_line *line, char *key)
{
    t_buf *tmp_buf;
    t_buf *new_buf;

    new_buf = NULL;
    if (!line || !line->cursor || !key)
        fatal("Error (insert_at_cursor)");
    new_buf = ft_new_buf(key);
    tmp_buf = get_cur_buffer(line);
    if (line->current_c->c_ind == line->last_c->c_ind)
    {
        tmp_buf->next = new_buf;
        new_buf->prev = tmp_buf;
    }
    if (tmp_buf->next) // If it's not the last buffer item
        tmp_buf = tmp_buf->prev;

    // TODO : insert the ne_buf item AFTER the tmp_buf element

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
