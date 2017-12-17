#include "../../includes/ft_sh.h"

/*
** counts the amount of columns the cursor is away
** from the end of the buffer
*/

int         get_cursor_pos(t_buf *buffer)
{
    int ret;
    t_buf *tmp;

    tmp = NULL;
    ret = 0;
    if (!buffer)
        fatal("Error (get_cursor_pos)");
    tmp = buffer;
    while (tmp && tmp->next && tmp->cursor == FALSE)
        tmp = tmp->next;
    while (tmp->next)
    {
        ret++;
        tmp = tmp->next;
    }
    return (ret);
}

/*
** clears the current line of the prompt
** before re - outputting the line buffer
*/

void        clear_prompt_line() // WIP
{
    //tputs(tgetstr("cl", NULL), 0, putintc);
    //tputs(tgetstr("cd", NULL), 0, putintc);
    tputs(tgetstr("ce", NULL), 0, putintc);

  
}

/*
** outputs the linked list which represents the buffer
** of keystrokes inputted by the user
** re-outputs buffer, thus also repositioning
** the cursor
*/

void        print_buffer(t_buf *buffer)
{
    t_buf   *tmp;
    int     i;
    int     n;

    i = 0;
    n = 0;
    tmp = NULL;
    if (!buffer)
        return ;
    n = list_len(buffer);

    while (i < n)
    { 
        tputs(tgetstr("le", NULL), 0, putintc);
        i++;
    }

    clear_prompt_line(); // TESTING



    tmp = buffer;
    while (tmp)
    {
        ft_putstr(tmp->key);
        tmp = tmp->next;
    }

}
