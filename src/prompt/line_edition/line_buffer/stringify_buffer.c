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
        return (NULL);
    tmp = buffer;
    i = list_len(tmp);
    ret = ft_strnew(i);
    while (tmp)
    {
        ret = ft_strcat(ret, tmp->key);
        tmp = tmp->next;
    }
    return (ret);
}
