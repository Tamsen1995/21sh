#include "../../../../includes/ft_sh.h"

/*
** stringifies the linked list of commands
*/

char        *stringify_buffer(t_buf  *buffer)
{
    char    *ret;
    int     i;
    t_buf   *tmp;

    ret = NULL;
    tmp = NULL;
    i = 0;
    if (!buffer)
        fatal("error in (stringify_buffer)");
    tmp = buffer;
    i = list_len(tmp);
    ret = ft_strnew(i);
    while (tmp->next)
    {
        ret = ft_strcat(ret, tmp->key);
        tmp = tmp->next;
    }
    return (ret);
}
