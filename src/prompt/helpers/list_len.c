#include "../../../includes/ft_sh.h"

/*
** iterates through an entire list
** and finds out the length of it
*/

int         list_len(t_buf *buffer)
{
    int     i;
    t_buf   *tmp;

    i = 0;
    tmp = NULL;
    if (!buffer)
        fatal("error in (list_len)");
    tmp = buffer;
    while (tmp)
    {
        i++;
        tmp = tmp->next;
    }
    return (i);
}

