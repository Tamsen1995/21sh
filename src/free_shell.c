#include "../includes/ft_sh.h"

/*
** Takes in an env_var and frees it
*/
void free_env_var(t_env *env_var)
{
    free(env_var->name);
    env_var->name = NULL;
    free(env_var->value);
    env_var->value = NULL;
    free(env_var);
    env_var = NULL;
}

/*
** Takes in the shell's environment and frees it
*/
void        free_env(t_env *env)
{
    t_env *tmp;
    
    tmp = NULL;
    tmp = env;
    if (!env)
        fatal("Error in (free_env)");
    while (tmp->next)
        tmp = tmp->next;
    while (tmp->prev)
    {
        tmp = tmp->prev;
        free_env_var(tmp->next);
    }
    free_env_var(tmp);
}

/*
** Takes in the shell and frees it
*/

void        free_shell(t_shell *shell)
{
    if (!shell)
        fatal("No shell to be freed in (free_shell)");
    if (shell->env != NULL)
        free_env(shell->env);
    if (shell->bin_dir != NULL)
        ft_strfree(shell->bin_dir);

// TODO        free_cmds_list(shell);

    free(shell);
    shell = NULL;
    // More might be implemented later as we add more variables onto the shell
}