#include "../../includes/ft_sh.h"

// TESTING
// Testing the buffer eveytime in order to see if desired elements have been executed
void           print_list_test(t_buf *buffer)
{
    t_buf *tmp;

    tmp = buffer;
    while (tmp)
    {
        ft_putstr(tmp->key);
        tmp = tmp->next;
    }
    exit(-1);
}

