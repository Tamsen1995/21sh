#include "../../../includes/ft_sh.h"

void    init_hist_index(t_hist *history)
{
    t_hist      *tmp_his;
    int         i;

    i = 1;
    tmp_his = NULL;
    if (!history)
        return ;
    tmp_his = history;
    while (tmp_his)
    {
        tmp_his->index = i;
        tmp_his = tmp_his->next;
        i++;
    }

}