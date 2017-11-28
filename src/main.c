#include "../includes/twenty_one_sh.h"

int main(int ac, char **av, char **envv) 
{
    t_shell *shell;

    shell = NULL;
    shell = init_shell(ac, av, envv);
    ft_putendl("Hello world");

    // Some kind of loop
    // make sure to pair every malloc with a free
    // The get_next_line could be useful in order to get a buffer

    return(0);
}


