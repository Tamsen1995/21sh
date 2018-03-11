#include "../../includes/ft_sh.h"

void dup_exec(t_shell *shell, int *pipe_fd, int fd_left)
{
	int save_fd;

	save_fd = dup(fd_left);
	close(pipe_fd[fd_left == STDOUT_FILENO ? 0 : 1]);
	dup2(pipe_fd[fd_left == STDOUT_FILENO ? 1 : 0], fd_left);
	close(pipe_fd[fd_left == STDOUT_FILENO ? 1 : 0]);
	sh_execute(shell);
	dup2(save_fd, fd_left);
	close(save_fd);
	fd_left == STDOUT_FILENO ? (void)wait(NULL) : exit(EXIT_SUCCESS);
}

void simply_dup_it(t_shell *shell, int fd_left, int fd_right)
{
	int fd_save;

	fd_save = dup(fd_left);
	close(fd_left); // not sure about this
	dup2(fd_right, fd_left);
	close(fd_right);
	sh_execute(shell);
	dup2(fd_save, fd_left);
	close(fd_save);
}

/*
** discern the left file descriptor as well as the 
** right one
** replace the left with the right one
*/

void dup_it(t_shell *shell, int default_left_fd)
{
	int fd_left;
	int fd_right;
	char **cmd;
	int i;

	i = 0;
	cmd = shell->cmds->args;
	fd_left = -1;
	fd_right = -1;


	while (cmd[i] && !ft_strchr(cmd[i], R_DUP_OUTPUT) && !ft_strchr(cmd[i], R_DUP_INPUT))
		i++;
	if ((fd_left = get_fd(cmd[i - 1])) == -1)
		fd_left = default_left_fd;
	if (!cmd[i + 1] || ((fd_right = get_fd(cmd[i + 1])) == -1 && ((fd_right = open(cmd[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0664)) == -1)))
		return(ft_putendl("parsing error"));
	shell->cmds->args = remove_redir_from_array(cmd, i);
	simply_dup_it(shell, fd_left, fd_right);
}
