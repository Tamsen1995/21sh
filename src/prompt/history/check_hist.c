#include "../../../includes/ft_sh.h"

/*
** replaces the buffer linked list
** with the given string.
** each character is going to be another element
** in the linked list
*/

t_buf        *replace_buffer(char *string)
{
    int         i;
    t_buf       *new_buf;
    char        key[2];

    i = 0;
    new_buf = NULL;
    if (!string)
        fatal("Error (replace_buf)");
    while (string[i])
    {
        ft_bzero(key, 2);
        key[0] = string[i];
        ft_add_buf(&new_buf, key);
        i++;
    }
    return (new_buf);
}


/*
** sets the cursor to the end of command line after
** the buffer has been changed 
** (like in the case of history checking for instance)
*/

void        cursor_toend(t_line *line)
{
    t_buf *tmp_buf;

    tmp_buf = NULL;
    if (!line || !line->buffer ||!line->cursor)
        fatal("Error (cursor_toend)");
    prompt_cursor(line);
    tmp_buf = line->buffer;
    while (tmp_buf)
    {
        line->current_c = line->current_c->next;
        tmp_buf = tmp_buf->next;
    }


}


/*
** everytime an arrow key is pressed
** the history list is checked backwards
** changing the buffer within the line structure
*/

void        check_hist(t_line *line)
{
    t_hist *tmp_his;

    tmp_his = NULL;
    if (!line || !line->history)
        fatal("Error (check_hist)");
    tmp_his = line->history;
    while (tmp_his && tmp_his->current == FALSE)
        tmp_his = tmp_his->next;
    if (tmp_his->prev)
    {
        tmp_his->current = FALSE;
        tmp_his->prev->current = TRUE;
    }
    free_buffer(line->buffer);
    line->buffer = replace_buffer(tmp_his->cmd);
 //   cursor_toend(line);
}