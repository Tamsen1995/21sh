#include "../includes/ft_sh.h"

// function that will either start a process or a builtin
int sh_execute(char **envv, t_shell *shell)
{
    // There was an empty command
    if (!shell->args || !shell->args[0])
        return (1);
    if (check_builtins(shell->args[0]) == TRUE || \
        check_builtin_path(shell) == TRUE)
        return (exec_builtin(shell));
    return (sh_launch(envv, shell));
}