#include "../../../includes/ft_sh.h"

void    check_hist_down(t_line *line)
{
    t_hist  *tmp_his;
    char    *replacement;

    tmp_his = NULL;
    replacement = NULL;
    if (!line)
        fatal("Error (check_hist_down)");
    if (!line->history)
        return ;
    if (line->his_index == 0)
        return ;
    else if (get_last_index(line->history) == line->his_index)
        replacement = "";
    else
    {
        line->his_index++;
        tmp_his = line->history;
        while (tmp_his && tmp_his->index != line->his_index)
            tmp_his = tmp_his->next;
        replacement = tmp_his->cmd;
    }
    free_buffer(line->buffer);
    line->buffer = replace_buffer(replacement);
    set_cursor_internal(line);
}