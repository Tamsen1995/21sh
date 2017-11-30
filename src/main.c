#include "../includes/ft_sh.h"

int         count_args(char **args)
{
    int argc;

    argc = 0;
    if (!args)
        return (0);
    while (args[argc])
        argc++;
    return (argc); // TODO test this function
}

/*
** receives a buffer with potential tabs in it
** makes a copy of this buffer in which the tabs
** are replaced with spaces
*/

char        *replace_tabs(char *buf)
{
    char *line;
    int i;

    i = 0;
    line = NULL;
    line = ft_strdup(buf);
    while (line[i])
    {
        if (line[i] == '\t')
            line [i] = ' ';
        i++;
    }
    return (line);
}

/*
** the main loop of the program
** intialize a prompt for the user
** Read a command from the standard input
** Parse it, meaning we seperate the command into a program and a set of arguments
*/

void        sh_loop(t_shell *shell, char **envv)
{
    int status;
    char *line;
    char *buf;

    status = 1;
    buf = NULL;
    line = NULL;
    while (status == 1) 
    {
        shell->args = NULL;
        ft_putstr("tamshell$> ");
        get_next_line(0, &buf);

        line = replace_tabs(buf);
        shell->args = ft_strsplit(line, ' '); // This needs to look different as individual arrays will have to be put into a linked list
        shell->cmds = store_commands(line);

        // This area will have to be reconstructed

        shell->argc = count_args(shell->args);
        status = sh_execute(envv, shell);

        ///////////////////////////////////

        ft_strfree(line);
        ft_strfree(buf);
        free_twod_arr(shell->args);
    }
}

/*
** A testing function to test if the previous pointer was properly implemented
*/

void        testing_prev(t_env *env)
{
    t_env *tmp;

    tmp = env;
    while (tmp->next)
        tmp = tmp->next;
    while (tmp->prev)
    {
        ft_putendl(tmp->name);
        tmp = tmp->prev;
    }
}

/*
** Initiating the shell
** then re-directing to the
** programs main loop
*/

int         main(int ac, char **av, char **envv)
{
    t_shell *shell;

    shell = NULL;
    shell = init_shell(ac, av, envv);
    sh_loop(shell, envv);  // the programs main loop
    free_shell(shell);
    return (0);
}

/*
** Execute and run the parsed command
** seperate processes and builtins
** a process will imply a child a process being split from its parent
** and then running seperately
** a builtin will be a command within the shell itself
*/