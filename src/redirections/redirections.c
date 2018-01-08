#include "../../includes/ft_sh.h"



T_BOOL			is_input_redir(char *redir, char *file)
{

	if (ft_strcmp(redir , "<") == 0 && access(file, W_OK) == 0)
		return (TRUE);
	return (FALSE);
}

/*
** will discern the redirections 
*/

void 			discern_redirs(t_shell *shell)
{
	int		i;
    char	**cmd_args;

	i = 0;
    cmd_args = shell->cmds->args;
	while (cmd_args[i + 1] && cmd_args[i])
	{
		if (is_input_redir(cmd_args[i], cmd_args[i + 1]))

		i++;
	}
	ft_putendl("EXITING PROGRAM IN (discern_redirs)");
	exit(-1);
}


/*
** sets up the fds for redirection
** before command execution
*/

void 			modify_fds()
{
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

	int fd1 = open("textfile.txt", O_CREAT | O_RDWR | O_TRUNC, mode);
    dup2(fd1, STDOUT_FILENO); 
	close(fd1);
}