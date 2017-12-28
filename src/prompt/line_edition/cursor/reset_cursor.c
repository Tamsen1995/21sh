#include "../../../../includes/ft_sh.h"

/*
** resets the cursor to the beginning
** of the current line it's on.
** only works in the absence of the termcap 
** 'bw'
*/

void        reset_cursor()
{
    tputs(tgetstr("cr", NULL), 0, putintc);
}