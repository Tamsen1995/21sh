#include "../../includes/ft_sh.h"

/*
** resets the cursor to the beginning
** of the current line it's on.
** only works in the absence of bw
*/

void        reset_cursor(t_line *line)
{
    int     i;

    i = 0;
    if (!line || !line->sz)
        fatal("Error (reset_cursor)");
    while (i < line->sz->ws_col)
    {
        tputs(tgetstr("le", NULL), 0, putintc);
        i++;
    }

}