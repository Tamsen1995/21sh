#include "../../includes/ft_sh.h"


enum e_redir	redir_type(char *redir, char *file)
{
	if (!redir || !file)
		fatal("Error (redir_type)");
	if (ft_strcmp(redir , "<") == 0 && access(file, W_OK) == 0)
		return (INPUT_RE);
	if (ft_strcmp(redir , ">") == 0 && access(file, W_OK) == 0)
		return (OUTPUT_RE);
	if (ft_strcmp(redir , "2>") == 0 && access(file, W_OK) == 0)
		return (ERR_RE);
	return (NO_REDIRECTION);
}



/*
** will discern the redirections 
*/

void 			discern_redirs(t_shell *shell)
{
	int		i;
    char	**cmd_args;

	i = 0;
	if (!shell || !shell->cmds || !shell->cmds->args)
		fatal("Error: (discern_redirs)");
    cmd_args = shell->cmds->args;
	while (cmd_args[i + 1] && cmd_args[i])
	{
		if (redir_type(cmd_args[i], cmd_args[i + 1]) == INPUT_RE)
			add_fd(&shell->cmds->in_fds, cmd_args[i + 1]);
		else if (redir_type(cmd_args[i], cmd_args[i + 1]) == OUTPUT_RE)
			add_fd(&shell->cmds->out_fds, cmd_args[i + 1]);
		else if (redir_type(cmd_args[i], cmd_args[i + 1]) == ERR_RE)
			add_fd(&shell->cmds->err_fds, cmd_args[i + 1]);
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