#include "../../includes/ft_sh.h"


/*
** positions the cursor at its proper position
** according to the cursor linked list
*/

void        set_cursor(t_line *line)
{
    t_cursor    *tmp;

    tmp = NULL;
    if (!line || !line->cursor)
        fatal("Error (set_cursor)");
    tmp = line->cursor;
    reset_cursor();
    while (tmp->c_ind != line->current_c->c_ind)
    {
        tputs(tgetstr("nd", NULL), 0, putintc);
        tmp = tmp->next;
    }
}

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
    set_cursor(line);
}
