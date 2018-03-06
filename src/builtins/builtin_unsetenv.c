#include "../../includes/ft_sh.h"

/*
** gets rid of an env var element and 
** frees all the memory associated with it
*/
void        del_env_var(t_env **elem)
{
    ft_strclr((*elem)->name);
    ft_strclr((*elem)->value);
    free((*elem)->name);
    free((*elem)->value);
    (*elem)->name = NULL;
    (*elem)->value = NULL;
    (*elem)->prev = NULL;
    (*elem)->next = NULL;
}

/*
** receives a linked element in a list
** and plans to remove it
*/
void        remove_elem(t_env **elem, t_env **begin_list)
{
    t_env *tmp;

    tmp = NULL;
    if (!(*elem))
        fatal("error: (*elem) missing in (remove_(*elem))");
    if ((*elem)->prev && (*elem)->next)
    {
        (*elem)->prev->next = (*elem)->next;
        (*elem)->next->prev = (*elem)->prev;
    }
    else if (!(*elem)->prev)
    {
        (*begin_list) = (*begin_list)->next;
        (*begin_list)->prev = NULL;
    }
    else if (!(*elem)->next)
        (*elem)->prev->next = NULL;
    del_env_var(elem);
}

t_bool     sh_unsetenv(char **args, t_shell *shell)
{
    int i;
    t_env *tmp;

    i = 1;
    tmp = NULL;
    if (!args || !shell)
        fatal("error: Missing args or shell vars");
    while (i < shell->argc)
    {
        tmp = shell->env;
        while (tmp)
        {
            if (ft_strcmp(args[i], tmp->name) == 0)
            {
                remove_elem(&tmp, &shell->env);
                free(tmp);
                tmp = NULL;
                break ;
            }
            tmp = tmp->next;
        }
        i++;
    }
    return (TRUE);
}
