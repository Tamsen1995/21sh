#include "../includes/ft_sh.h"


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
    if (!(line = ft_strdup(buf)))
        return (NULL);
    while (line[i])
    {
        if (line[i] == '\t')
            line [i] = ' ';
        i++;
    }
    return (line);
}


/*

** This routine will read the characters of the line buffer
** check them into a linked list
** make sure of the cursor position (check for its position and modify it)
** insert text at the appropiate line
** attune the terminal in a way which will make the reading all the characters possible

** Display the initial contents of the text buffer on the screen.
** Get a keystroke from the user.
** If the keystroke is a command (like delete or backspace), dispatch or carry out that command.
** If the keystroke is a character, insert it into the text buffer (or replace the current character if not in insert mode).
** Display the updated contents of the text buffer on the screen.
*/
char        *prompt_loop(void)
{

    char *buf;

    buf = NULL; // TESTING
    ft_putstr("tamshell$> ");
    get_next_line(0, &buf);
    // somewhere here I need to check for input
    // to see if there is an arrow key  I need to be able
    // to read. This will constitute for the cursor movement

    return (buf);
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

        buf = prompt_loop();
        
        line = replace_tabs(buf);
        shell->cmds = store_commands(line);

        // Executes the list of commands that was given to the program
        // This list of commands is seperated by the ";" sign
        while (shell->cmds)
        {
            shell->argc = count_args(shell->cmds->args);
            status = sh_execute(envv, shell);
            shell->cmds = shell->cmds->next;
        }
        ////////////////////////////////////
        ft_strfree(line);
        ft_strfree(buf);
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
