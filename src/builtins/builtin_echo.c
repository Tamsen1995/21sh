#include "../../includes/ft_sh.h"

/*
** man echo
*/

int sh_echo(char **args)
{
    int i;

    i = 1;
    while (args[i])
    {
        ft_putstr(args[i]);
        ft_putchar(' ');
        i++;
    }
    ft_putendl("");
    return (1);
}
