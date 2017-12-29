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
** everytime an arrow key is pressed
** the history list is checked backwards
** changing the buffer within the line structure
*/

void        check_hist(t_line *line)
{
    t_hist *tmp_his;

    tmp_his = NULL;
    if (!line)
        fatal("Error (check_hist)");
    if (!line->history)
        return ;
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
    set_cursor_internal(line);
}