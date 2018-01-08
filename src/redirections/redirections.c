#include "../../includes/ft_sh.h"



T_BOOL			is_input_redir(char *redir, char *file)
{

	if (ft_strcmp(redir , "<") == 0 && access(file, W_OK) == 0)
		return (TRUE);
	return (FALSE);
}


void			reset_fd_arr(int *fd_arr)
{
	fd_arr[0] = 0;
	fd_arr[1] = 1;
	fd_arr[2] = 2;
}


int				get_fd(char *file)
{
	int		fd;
	mode_t	mode;

	fd = 0;
	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	if ((fd = open(file, O_CREAT | O_RDWR | O_TRUNC, mode)) < 0)
		fatal("Could not open in (get_fd)");
	return (fd);
}


/*
** will discern the redirections 
*/

void 			discern_redirs(t_shell *shell)
{
	int		i;
    char	**cmd_args;
	int		fd_arr[3];

	i = 0;
    cmd_args = shell->cmds->args;
	while (cmd_args[i + 1] && cmd_args[i])
	{
		reset_fd_arr(fd_arr);
		if (is_input_redir(cmd_args[i], cmd_args[i + 1]))
			fd_arr[0] = get_fd(cmd_args[i + 1]);
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