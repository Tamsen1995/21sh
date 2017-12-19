#include "../../../includes/ft_sh.h"

/*
** gets the first cursor position which shall be
** right after the prompt
*/

t_cursor       *get_first_c(t_line *line)
{
    int             i;
    int             prompt_len;
    t_cursor        *first;

    i = 0;
    prompt_len = 0;
    first = NULL;
    if (!line || !line->cursor)
        fatal("Error (get_first_c)");
    prompt_len = ft_strlen(line->prompt);
    first = line->cursor;
    while (first && i < prompt_len)
    {
        i++;
        first = first->next;
    }
    return (first);
}