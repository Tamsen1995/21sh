#include "../../../includes/ft_sh.h"

/*
** resets the cursor to the beginning
** of the current line it's on internally
*/

void        reset_cursor_internal(t_line *line)
{
    while (line->current_c->prev)
        line->current_c = line->current_c->prev;
    while (line->last_c->prev)
        line->last_c = line->last_c->prev;
}

/*
** resets the cursor to the beginnging of the prompt
** internally
*/

void        prompt_cursor_internal(t_line *line)
{
    int     i;
    int     prompt_len;

    i = 0;
    prompt_len = 0;
    if (!line || !line->prompt)
        fatal("Error: (reset_cursor)");
    prompt_len = ft_strlen(line->prompt);
    reset_cursor_internal(line);
    while (i < prompt_len && line->current_c)
    {
        line->current_c = line->current_c->next;
        line->last_c = line->last_c->next;
        i++;
    }
}

/*
** sets the cursor to the end of command line after
** the buffer has been changed 
** (like in the case of history checking for instance)
*/

void        set_cursor_internal(t_line *line)
{
    t_buf *tmp_buf;

    tmp_buf = NULL;
    if (!line ||!line->cursor)
        fatal("Error (set_cursor_internal)");
    prompt_cursor_internal(line);
    tmp_buf = line->buffer;
    while (tmp_buf) 
    {
        line->current_c = line->current_c->next;
        line->last_c = line->last_c->next;
        tmp_buf = tmp_buf->next;
    }
}
