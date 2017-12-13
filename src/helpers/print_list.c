#include "../../includes/ft_sh.h"


int         count_linked_list()
{
    
}

/*
** outputs the linked list which represents the buffer
** of keystrokes inputted by the user
*/

void        print_buffer(t_buf *buffer)
{
    t_buf *tmp;

    tmp = NULL;
    if (!buffer)
        fatal("Error in (print_buffer)");

     
        // count the amt of keys within a list, this will equal to n
        // MAYBE make the cursor invisible
        // move the cursor n columns to the left with         tputs(tgetstr("ce", NULL), 0, putintc);
        // print the new buffer line // print_buffer(buffer);
        // move the cursor back to the end of the line being edited



    tmp = buffer;
    while (tmp)
    {
        ft_putstr(tmp->key);
        tmp = tmp->next;
    }

}
