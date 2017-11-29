#include "../includes/ft_sh.h"

// initiaing the shell and the data required for it
t_shell     *init_shell(int ac, char **av, char **envv)
{
    t_shell *shell;

    shell = NULL;
    av = NULL;
    ac = 0;
    if (!(shell = (t_shell *)malloc(sizeof(t_shell))))
        fatal("Couldn't allocate shell in init_shell");
    shell->env = init_env(envv);
    shell->argc = 0;
    shell->args = NULL;
    shell->path_var = NULL;
    shell->bin_dir = NULL;
    return (shell); // TESTING
}