#include "../includes/ft_sh.h"

/*
** a function to secure the launch of the terminal in the beginning
*/

void        launch_error_check(char **envv)
{
    if (isatty(STDIN_FILENO) == 0)
        fatal("Not a terminal device");
    if (!envv)
        fatal("No environment present");
}
