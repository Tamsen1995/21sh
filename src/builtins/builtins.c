#include "../../includes/ft_sh.h"


/*
** gets in the potential path of a binary
** and checks to see if it is the path of a builtin
*/

T_BOOL      is_builtin_path(t_shell *shell)
{
    int i;
    char **bin_path_split; // the binary path split up
    T_BOOL ret;
    
    i = 0;
    ret = FALSE;
    bin_path_split = NULL;
    bin_path_split = ft_strsplit(shell->cmds->args[0], '/');
    while (bin_path_split[i + 1])
        i++;
    ret = check_builtins(bin_path_split[i]);
    free_twod_arr(bin_path_split);
    return (ret);
}

/*
** check the given directory (path)
** for eventual matches with the given shell argument as well
** as it being a match with a builtin
** if both cases are true it returns TRUE
*/

T_BOOL      iter_builtin_bin_paths(char *bin_dir, t_shell *shell)
{
    DIR             *dir;
    struct  dirent  *ent;
    char            *file_path;

    dir = NULL;
    ent = NULL;
    file_path = NULL;
    dir = safe_opendir(bin_dir);
    while ((ent = readdir(dir)))
    {
        file_path = make_file_path(bin_dir, ent->d_name);
        if (ft_strcmp(file_path, shell->cmds->args[0]) == 0 &&
            is_builtin_path(shell) == TRUE)
        {
            closedir(dir);
            ft_strfree(file_path);
            return (TRUE);
        }
        ft_strfree(file_path);
    }
    closedir(dir);
    return (FALSE);
}


/*
** Goes through through all the binaries in the PATH variable
** compares all the paths for the individual binaries
** with the argument given
** if there is a match it return true
*/

T_BOOL      check_builtin_path(t_shell *shell)
{
    char    **bin_dirs;
    int     i;

    i = 0;
    bin_dirs = NULL;
    get_path_var(shell);
    if (!shell->path_var)
        return (FALSE);
    bin_dirs = ft_strsplit(shell->path_var, ':');
    while (bin_dirs[i])
    {
        if (iter_builtin_bin_paths(bin_dirs[i], shell))
        {
            free_twod_arr(bin_dirs);
            ft_strfree(shell->path_var);
            return (TRUE);
        }
        i++;
    }
    ft_strfree(shell->path_var);
    free_twod_arr(bin_dirs);
    return (FALSE);
}

/*
** simply checks the argument array for
** a builtin command
*/

T_BOOL check_builtins(char *cmd)
{
    if (ft_strcmp(cmd, "echo") == 0)
        return (TRUE);
    if (ft_strcmp(cmd, "cd") == 0)
        return (TRUE);
    if (ft_strcmp(cmd, "setenv") == 0)
        return (TRUE);
    if (ft_strcmp(cmd, "unsetenv") == 0)
        return (TRUE);
    if (ft_strcmp(cmd, "env") == 0)
        return (TRUE);
    if (ft_strcmp(cmd, "exit") == 0)
        return (TRUE);
    return (FALSE);
}

/*
** makes builtin command from the path 
** of the builtin binary provided
*/

char        *builtin_cmd_from_path(t_shell *shell)
{
    char        **bin_path_split;
    char        *ret;
    int         i;

    i = 0;
    ret = NULL;
    bin_path_split = NULL;
    if (!shell || !shell->cmds->args[0])
        fatal("Error in (builtin_cmd_from_path)");
    bin_path_split = ft_strsplit(shell->cmds->args[0], '/');
    while (bin_path_split[i + 1])
        i++;
    ret = ft_strdup(bin_path_split[i]);
    free_twod_arr(bin_path_split);
    return (ret);
}

/*
** redirects the flow to the appropiate
** builtin
** returns whatever the builtin returns
*/

int         exec_builtin(t_shell *shell)
{
    if (check_builtin_path(shell) == TRUE)
    {
        ft_strfree(shell->cmds->args[0]);
        shell->cmds->args[0] = builtin_cmd_from_path(shell);
    }
    if (ft_strcmp(shell->cmds->args[0], "echo") == 0)
        return (sh_echo(shell->cmds->args));
    if (ft_strcmp(shell->cmds->args[0], "cd") == 0)
        return (sh_cd(shell->cmds->args, shell));
    if (ft_strcmp(shell->cmds->args[0], "setenv") == 0)
        return (sh_setenv(shell->cmds->args, shell));
    if (ft_strcmp(shell->cmds->args[0], "unsetenv") == 0)
        return (sh_unsetenv(shell->cmds->args, shell));
    if (ft_strcmp(shell->cmds->args[0], "env") == 0)
        return (sh_env(shell));
    if (ft_strcmp(shell->cmds->args[0], "exit") == 0)
        return (sh_exit());
    fatal("Error in exec_builtin: builtin recognized, but flow not properly redirected");
    return (0);
}
