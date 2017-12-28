#include "../../includes/ft_sh.h"

/*
** outputs the linked list which represents the buffer
** of keystrokes inputted by the user
** re-outputs buffer, thus also repositioning
** the cursor
*/

void        print_buffer(t_line *line)
{
    t_buf   *tmp;

    tmp = NULL;
    prompt_cursor(line);
    tmp = line->buffer;
    while (tmp)
    {
        ft_putstr(tmp->key);
        tmp = tmp->next;
    }
}
