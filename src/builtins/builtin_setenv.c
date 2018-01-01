#include "../../includes/ft_sh.h"

/*
** gets an argument array with name and value of an
** envv variable which is already present in the env list
** iterates to that variable and changes it
*/

void        change_env_var(char **args, t_shell *shell)
{
    t_env       *env_tmp;
    char        *name;
    char        *nw_value;

    name = NULL;
    nw_value = NULL;
    env_tmp = NULL;
    env_tmp = shell->env;
    if (!args[1])
        fatal("No name in (change_env_var)");
    if (!args[2])
        fatal("Value missing in (change_env_var)");
    name = ft_strdup(args[1]);
    nw_value = ft_strdup(args[2]);
    while (env_tmp && ft_strcmp(env_tmp->name, name) != 0)
        env_tmp = env_tmp->next;
    ft_strfree(env_tmp->value);
    env_tmp->value = ft_strdup(nw_value);
    ft_strfree(name);
    ft_strfree(nw_value);
}


/*
** checks the arguments for the appropiate parameters
** goes on to allocate a new list element onto
** the end of the env vars list
** if the given variable already exists then it changes it in the envv list
*/

int     sh_setenv(char **args, t_shell *shell)
{
    t_env *tmp_env;

    tmp_env = NULL;
    if (!args || !shell)
        fatal("Error: no args present in (sh_setenv)");
    tmp_env = shell->env;
    if (shell->argc == 1)
        sh_env(shell);
    else if (shell->argc > 3)
    {
        ft_putendl("minishell: Too many arguments");
        return (1);
    } 
    while (tmp_env->next && ft_strcmp(tmp_env->name, args[1]) != 0)
        tmp_env = tmp_env->next;
    if (ft_strcmp(tmp_env->name, args[1]) == 0)
        change_env_var(args, shell);
    else
        ft_putenv(&shell->env, args[1], args[2]);
    return (1);
}