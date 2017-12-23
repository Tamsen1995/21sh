#include "../../includes/ft_sh.h"

/*
** resets the cursor to the beginning
** of the current line it's on.
** only works in the absence of the termcap 
** 'bw'
*/

void        reset_cursor()
{
    int     i;
    struct winsize *ret;

    i = 0;

    if (!(ret = (struct winsize *)malloc(sizeof(struct winsize) * 1)))
        fatal("Can't allocate size struct (make_shell)");
    ioctl(0, TIOCGWINSZ, ret);
    while (i < ret->ws_col)
    {
        tputs(tgetstr("le", NULL), 0, putintc);
        i++;
    }
    free(ret);
}