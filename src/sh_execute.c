#include "../includes/ft_sh.h"

/*
** will redirect towards the redirections flow
** , the builtin flow
** or the normal flow
*/

int sh_execute(char **envv, t_shell *shell)
{
    if (!shell->cmds->args || !shell->cmds->args[0])
        return (1);

    shell->cmds->args = assign_redirections(shell->cmds->args); // WIP
    exec_redirection(shell->cmds->args);                        // WIP

    exit(-1); // TESTING

    if (check_builtins(shell->cmds->args[0]) == TRUE ||
        check_builtin_path(shell) == TRUE)
        return (exec_builtin(shell));

    return (sh_launch(envv, shell));
}
