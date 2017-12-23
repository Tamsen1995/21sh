#include "../../includes/ft_sh.h"


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
    while (tmp->next)
    {
        i++;
        tmp = tmp->next;
    }
    return (i);
}

/*
** resets the cursor to the beginnging of the prompt
*/

void        prompt_cursor(t_line *line)
{
    int     i;
    int     prompt_len;

    i = 0;
    prompt_len = 0;
    if (!line || !line->prompt)
        fatal("Error: (reset_cursor)");
    prompt_len = ft_strlen(line->prompt);
    reset_cursor(line);
    while (i < prompt_len)
    {
        tputs(tgetstr("nd", NULL), 0, putintc);
        i++;
    }
    tputs(tgetstr("ce", NULL), 0, putintc);
}

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
    reset_cursor(line);
    while (tmp->c_ind != line->current_c->c_ind)
    {
        tputs(tgetstr("nd", NULL), 0, putintc);
        tmp = tmp->next;
    }



    // move cursor all the way to the beginning

    // move cursor to the right in conjunction with the cursor linked list
    // until the current_c tracked position has been reached

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
    int     n;

    n = 0;
    tmp = NULL;
    if (!line->buffer)
        return ;
    n = list_len(line->buffer);
    prompt_cursor(line);
    tmp = line->buffer;
    while (tmp)
    {
        ft_putstr(tmp->key);
        tmp = tmp->next;
    }
    set_cursor(line);
}
