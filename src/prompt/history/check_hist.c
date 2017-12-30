#include "../../../includes/ft_sh.h"

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