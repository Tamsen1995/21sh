#include "../../../includes/ft_sh.h"


/*
** since each history element has an index, 
** this function will iterate to the last link in the list and then
** get the last index to return it
*/

int         get_last_index(t_hist *history)
{
    t_hist *tmp_his;

    tmp_his = NULL;
    if (!history)
        fatal("Error (get_Last_index)");
    tmp_his = history;
    while (tmp_his->next)
        tmp_his = tmp_his->next;
    return (tmp_his->index);
}

/*
** declares indexes for the entire history list iteratively.
*/

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