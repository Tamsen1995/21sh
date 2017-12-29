#include "../../../includes/ft_sh.h"


/*
** allocates a new buffer list element
*/

t_hist *ft_new_his(char *cmd)
{
    t_hist *new;

    if (!(new = (t_hist *)malloc(sizeof(t_hist))))
        fatal("Error: could not allocate env var list elem in ft_new_env");
    new->next = NULL;
    new->prev = NULL;
    new->cmd = NULL;
    new->current = TRUE;
    new->cmd = ft_strdup(cmd);
    return (new);
}


/*
** adds an element to the end of the history list
** and makes every element of it false, except for the
** last one which is to be set to true.
*/

void        add_history(t_hist **history, char *cmd)
{
    t_hist *new_his;
    t_hist *tmp_his;

    new_his = NULL;
    tmp_his = NULL;
    if (!history || !cmd)
        return ;
    if (!(*history))
    {
        (*history) = ft_new_his(cmd);
        return ;
    }
    tmp_his = (*history);
    new_his = ft_new_his(cmd);
    while (tmp_his->next)
        tmp_his = tmp_his->next;
    tmp_his->current = FALSE;
    tmp_his->next = new_his;
    new_his->prev = tmp_his;
}
