#include "../../includes/ft_sh.h"

// Solely responsible for printing of all 
// envirionment variables
int        sh_env(t_shell *shell)
{
    t_env *env_var;

    env_var = NULL;
    if (!shell || !shell->env)
        fatal("There was an error in (sh_env)");
    env_var = shell->env;
    while (env_var)
    {
        if (env_var->name)
        {
            ft_putstr(env_var->name);
            ft_putstr("=");
        }
        if (env_var->value)
            ft_putendl(env_var->value);
        else
            ft_putendl("");
        env_var = env_var->next;
    }
    return (1);
}