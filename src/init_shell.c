#include "../includes/ft_sh.h"

/*
** applied the set flags of the termios struct
** onto the terminal
*/

void apply_mode(t_shell *shell)
{
    if (tcsetattr(0, TCSAFLUSH, shell->term) == -1)
        fatal("Error in (apply_mode)");
}

/*
** makes a new shell which should
** be set into raw mode 
*/

t_shell *make_shell(t_shell *shell)
{

    if (!(shell->sz = (struct winsize *)malloc(sizeof(struct winsize) * 1)))
        fatal("Can't allocate size struct (make_shell)");
    if (!(shell->term = (struct termios *)malloc(sizeof(struct termios) * 1)))
        fatal("Could not alloc (make_shell)");
    if (!(shell->termold = (struct termios *)malloc(sizeof(struct termios) * 1)))
        fatal("Could not alloc termold (make_shell)");
    if (tcgetattr(0, shell->termold) == -1)
        fatal("Could not get attributes for terminal (make_shell)");
    if (tcgetattr(0, shell->term) == -1)
        fatal("Could not get attributes for terminal (make_shell)");
    ioctl(0, TIOCGWINSZ, shell->sz);
    tputs(tgetstr("vi", NULL), 1, putintc);
    shell->term->c_lflag &= ~(ECHO);
    shell->term->c_lflag &= ~(ICANON);
    apply_mode(shell);
    return (shell);
}

t_shell *init_shell(int ac, char **av, char **envv)
{
    t_shell *shell;

    shell = NULL;
    av = NULL;
    ac = 0;
    if (!(shell = (t_shell *)malloc(sizeof(t_shell) * 1)))
        fatal("Couldn't allocate shell in (init_shell)");
    shell->history = NULL;
    shell->env = init_env(envv);
    shell->env_arr = update_env_arr(shell->env);
    shell->argc = 0;
    shell->cmds = NULL;
    shell->path_var = NULL;
    shell->bin_dir = NULL;
    shell = make_shell(shell);
    return (shell);
}

/*

** since the shell variable in this one is
** static it will remember the state of the shell
** in between function calls
** thus creating a quasi global variable


t_shell            *get_shell(void)
{
    static t_shell *shell = NULL;

    if (shell == NULL)
        shell = make_shell();
    update_window_size(shell);
    return (shell);
}

*/