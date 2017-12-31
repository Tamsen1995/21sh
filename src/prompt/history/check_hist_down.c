#include "../../../includes/ft_sh.h"

void    check_hist_down(t_line *line)
{
    t_hist *tmp_his;

    tmp_his = NULL;
    if (!line)
        fatal("Error (check_hist_down)");
    if (!line->history)
        return ;
    if (line->his_index == 0)
        return ;
    else if (get_last_index(line->history) == line->his_index)
    {
        fatal("Buffer needs to be deleted in (check_hist_down)");
      // TODO : delete the buffer
    }
    else
        line->his_index++;
    tmp_his = line->history;
    while (tmp_his && tmp_his->index != line->his_index)
        tmp_his = tmp_his->next;
    free_buffer(line->buffer);
    line->buffer = replace_buffer(tmp_his->cmd);
    set_cursor_internal(line);
}