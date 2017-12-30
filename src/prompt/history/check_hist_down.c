#include "../../../includes/ft_sh.h"

void    check_hist_down(t_line *line)
{
    t_hist *tmp_his;

    tmp_his = NULL;
    if (!line)
        fatal("Error (check_hist_down)");
    if (!line->history)
        return ;
    tmp_his = line->history;
    while (tmp_his && tmp_his->current == FALSE)
        tmp_his = tmp_his->next;
    if (!tmp_his->next)
        return ;

    tmp_his->current = FALSE;
    tmp_his = tmp_his->next;
    tmp_his->current = TRUE;

    ft_putendl(tmp_his->cmd); // TESTING


    free_buffer(line->buffer);
    line->buffer = replace_buffer(tmp_his->cmd);
    set_cursor_internal(line);
}