#include "../../includes/ft_sh.h"

/*
** returns the amount of elements within
** a linked list
*/

int         count_linked_list(t_buf *buffer)
{
    int i;
    t_buf *tmp;

    tmp = NULL;
    i = 0;
    if (!buffer)
        fatal("Error (count_linked_list)");
    tmp = buffer;
    while (tmp->next)
    {
        i++;
        tmp = tmp->next;
    }
    return (i);
}

/*
** outputs the linked list which represents the buffer
** of keystrokes inputted by the user
*/

void        print_buffer(t_buf *buffer)
{
    t_buf   *tmp;
    int     n;
    int     i;

    tmp = NULL;
    n = 0;
    i = 0;
    if (!buffer)
        return ;
    n = count_linked_list(buffer);

    // moving the cursor back to the prompt
    while (i < n)
    {
        tputs(tgetstr("le", NULL), 0, putintc);
        i++;
    }

    // re-outputs buffer, thus also repositioning
    // the cursor
    tmp = buffer;
    while (tmp)
    {
        ft_putstr(tmp->key);
        tmp = tmp->next;
    }

}
