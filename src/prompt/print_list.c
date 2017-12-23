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

void        reset_cursor(t_line *line)
{
    int     i;
    int     prompt_len;

    i = 0;
    prompt_len = 0;
    if (!line || !line->prompt)
        fatal("Error: (reset_cursor)");
    prompt_len = ft_strlen(line->prompt);
    while (i < line->sz->ws_col)
    {
        tputs(tgetstr("le", NULL), 0, putintc);
        i++;
    }
    i = 0;
    while (i < prompt_len)
    {
        tputs(tgetstr("nd", NULL), 0, putintc);
        i++;
    }
    tputs(tgetstr("ce", NULL), 0, putintc);
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
    reset_cursor(line);
    tmp = line->buffer;
    while (tmp)
    {
        ft_putstr(tmp->key);
        tmp = tmp->next;
    }

}
