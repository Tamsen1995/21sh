#include "../includes/ft_sh.h"

/*
** allocates a new environment variables list element
*/

t_cmds      *ft_new_cmd(char *command)
{
    t_cmds *new;

    if (!(new = (t_cmds *)malloc(sizeof(t_cmds))))
        fatal("Error: could not allocate env var list elem in ft_new_env");
    new->next = NULL;
    new->prev = NULL;
    new->args = NULL;
    new->args = ft_strsplit(command, ' ');
    return (new);
}

/* 
** iterates to the end of the cmd list
** and then adds the value to it
*/

void		ft_add_cmd(t_cmds **begin_list, char *command)
{
    t_cmds *tmp;

    tmp = NULL;
	if (!*begin_list)
	{
		*begin_list = ft_new_cmd(command);
		return ;
	}
    else
    {
        tmp = *begin_list;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = ft_new_cmd(command);
        tmp->next->prev = tmp;
    }
}

/*
** receives a string with potential commands in it
** these commands will be seperated by the ";" sign
** returns a list with commands and their arguments
*/

t_cmds      *store_commands(char *commands)
{
    char    **cmds_arr; // an array to temporarily store the commands inside
    t_cmds  *ret;
    int     i;

    cmds_arr = NULL;
    ret = NULL;
    i = 0;
    cmds_arr = ft_strsplit(commands, ';');

    // If there aren't several commands we just return the
    // initial one
    
    if (!cmds_arr)
    {
        ft_add_cmd(&ret, commands);
        return (ret);
    }
    
    while (cmds_arr[i]) // while there are potential commands
    {
        ft_add_cmd(&ret, cmds_arr[i]);
        i++;
    }
    free_twod_arr(cmds_arr);
    return (ret);
}