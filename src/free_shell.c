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
** A function which aims to free a command structure from
** the linked list
*/

// NOT IN HEADER 
void            free_cmd(t_cmds *cmd)
{
    if (cmd->args)
        free_twod_arr(cmd->args);
    if (cmd)
        free(cmd);
    cmd = NULL;
}


/*
** A function which free the list of commands in the shell backwards
*/

// NOT IN HEADER
void        free_cmds_list(t_shell *shell)
{
    t_cmds *tmp;

    tmp = NULL;
    tmp = shell->cmds;
    while (tmp->next) // Going towards the end first
        tmp = tmp->next;
    while (tmp->prev)
    {
        tmp = tmp->prev;
        free_cmd(tmp->next);
    }
    //   free_cmd(tmp); // fenceposting
}

/*
** function to free the history of
** the line
*/

void        free_line_history(t_hist *history)
{
    t_hist *tmp_his;

    tmp_his = NULL;
    if (!history)
        fatal("Error in (free_line_history)");
    tmp_his = history;
    while (tmp_his->next)
        tmp_his = tmp_his->next;
    while (tmp_his->prev)
    {
        tmp_his = tmp_his->prev;
        ft_strfree(tmp_his->next->cmd);
        free(tmp_his->next);
    }
    ft_strfree(tmp_his->cmd);
    free(tmp_his);
}

/*
** Takes in the shell and frees it
*/

void        free_shell(t_shell *shell)
{
    if (!shell)
        fatal("No shell to be freed in (free_shell)");
    if (shell->env)
        free_env(shell->env);
    if (shell->bin_dir)
        ft_strfree(shell->bin_dir);
    if (shell->cmds)
        free_cmds_list(shell);
    if (shell->history)
        free_line_history(shell->history);
    free(shell);
    shell = NULL;
}