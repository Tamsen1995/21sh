#include "../includes/ft_sh.h"

// allocates a new environment variables list element
t_env       *ft_new_env(char *name, char *value)
{
    t_env *new;

    if (!(new = (t_env *)malloc(sizeof(t_env))))
        fatal("Error: could not allocate env var list elem in ft_new_env");
    new->next = NULL;
    new->prev = NULL;
    new->name = ft_strdup(name);
    new->value = ft_strdup(value);
    return (new);
}

// iterates to the end of the env list
// and then adds the value to it
void		ft_putenv(t_env **begin_list, char *name, char *value)
{
    t_env *tmp;

    tmp = NULL;
	if (!*begin_list)
	{
		*begin_list = ft_new_env(name, value);
		return ;
	}
    else
    {
        tmp = *begin_list;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = ft_new_env(name, value);
        tmp->next->prev = tmp;
    }
}

// Takes in the environmnet vars
// and allocates a list with all the env vars in it
t_env       *init_env(char **envv)
{
    
    t_env *env_list;    
    char **env_var; // each individual env var split into name and value
    int i;

    i = 1;
    env_var = NULL;
    env_var = ft_strsplit(envv[0], '=');
    env_list = ft_new_env(env_var[0], env_var[1]);
    free_twod_arr(env_var);
    while (envv[i])
    {
        env_var = ft_strsplit(envv[i], '=');
        ft_putenv(&env_list, env_var[0], env_var[1]);
        free_twod_arr(env_var);
        i++;
    }
    return (env_list);
}