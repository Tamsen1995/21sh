#include "../../includes/ft_sh.h"

/*
** inputs an arbitrary int into
** the stdin
*/

int             putintc(int c)
{
    write(STDIN_FILENO, &c, 1);
    return (0);
}
