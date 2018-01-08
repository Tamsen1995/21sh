#include "../../includes/ft_sh.h"



T_BOOL			is_input_redir(char *redir, char *file)
{
	if (!redir || !file)
		fatal("Error (is_input_redir)");
	if (ft_strcmp(redir , "<") == 0 && access(file, W_OK) == 0)
		return (TRUE);
	return (FALSE);
}

/*
** gets the fd of a file through its name
*/

int				get_fd(char *file)
{
	int		fd;
	mode_t	mode;

	fd = 0;
	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	if (!file)
		fatal("Error: (get_fd)");
	if ((fd = open(file, O_CREAT | O_RDWR | O_TRUNC, mode)) < 0)
		fatal("Could not open in (get_fd)");
	return (fd);
}

t_fds		*ft_new_fd(char *file_name)
{
	int			new_fd;
	t_fds		*new;

	new = NULL;
	new_fd = 0;
	if (!file_name)
		fatal("Error (ft_new_in_fd)");
	if (!(new = (t_fds *)malloc(sizeof(t_fds) * 1)))
		fatal("Malloc error: (ft_new_in_fd)");
	new->fd =  get_fd(file_name);
	new->next = NULL;
	return (new);
}


void		add_fd(t_fds **begin_list, char *file_name)
{
	t_fds *tmp;

	tmp = NULL;
	if (!(*begin_list))
	{
		(*begin_list) = ft_new_fd(file_name);
		return ;
	}
	tmp = (*begin_list);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_new_fd(file_name);
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
		if (is_input_redir(cmd_args[i], cmd_args[i + 1]))
			add_fd(&shell->cmds->in_fds, cmd_args[i + 1]);
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