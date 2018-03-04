#include "../includes/ft_sh.h"

/*
** takes a t_env list element
** and makes a conventional env string out of it
*/

char *make_env_string(t_env *env_elem)
{
    char *ret;

    ret = NULL;
    if (!env_elem)
        return (NULL);
    ret = ft_strdup(env_elem->name);
    ret = ft_strjoin(ret, "=");
    ret = ft_strjoin(ret, env_elem->value);
    return (ret);
}

/*
** allocates a new 2d array of environment variables, going off the env list
** make sure to always free the old env before calling this
*/

char **update_env_arr(t_env *env_list)
{
    int i;
    char **env_arr;
    t_env *tmp_env;

    i = list_len_env(env_list);
    tmp_env = env_list;
    if (!env_list)
        return (NULL);
    env_arr = ft_alloc_twod_arr(i);
    i = 0;
    while (tmp_env)
    {
        env_arr[i] = make_env_string(tmp_env);
        i++;
        tmp_env = tmp_env->next;
    }
    return (env_arr);
}

/*
** initiating the shell and the data required for it
** setting the shell into what I believe to be canonical
** mode
*/