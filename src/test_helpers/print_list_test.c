#include "../../includes/ft_sh.h"

// TESTING
void           print_list_test(t_buf *buffer)
{
    t_buf *tmp;

    tmp = buffer;
    while (tmp)
    {
        ft_putstr(tmp->key);
        tmp = tmp->next;
    }
}

