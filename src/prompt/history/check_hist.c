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
    if (!line || !line->history)
        fatal("Error (check_hist)");
    tmp_his = line->history;
    while (tmp_his)
    {   
        ft_putendl(tmp_his->cmd);
        tmp_his = tmp_his->next;
    }
}