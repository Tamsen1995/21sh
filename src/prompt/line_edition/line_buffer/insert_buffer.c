#include "../../../../includes/ft_sh.h"

/*
** inserts the desired buffer key at
** the current cursor position
*/

void        insert_at_cursor(t_line *line, char *key)
{
    t_buf *tmp_buf;
    t_cursor *tmp_cur;
    if (!line || !line->cursor)
        fatal("Error (insert_at_cursor)");
    tmp_buf = line->buffer;
    tmp_cur = line->first_c;
    while (tmp_buf->next && tmp_cur->next && tmp_cur->c_ind != line->current_c->c_ind)
    {
        tmp_buf = tmp_buf->next;
        tmp_cur = tmp_cur->next;
    }
    if (!tmp_buf->next)
        tmp_buf->next = ft_new_buf(key);
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
