#include "../../includes/ft_sh.h"

char **get_before_pipe(char **cmd_cpy)
{
	int i;
	char **ret;

	i = 0;
	while (cmd_cpy[i] && !ft_strchr(cmd_cpy[i], R_PIPELINE))
		i++;
	ret = ft_alloc_twod_arr(i);
	i = 0;
	while (cmd_cpy[i] && !ft_strchr(cmd_cpy[i], R_PIPELINE))
	{
		ret[i] = ft_strdup(cmd_cpy[i]);
		i++;
	}
	return (ret);
}

char **get_after_pipe(char **cmd_cpy)
{
	char **ret;

	while (*(cmd_cpy) && !ft_strchr(*(cmd_cpy), R_PIPELINE))
		cmd_cpy++;
	cmd_cpy++;
	ret = ft_copy_twod_arr(cmd_cpy);
	return (ret);
}

static void fork_and_pipe(t_shell *shell, char **cmd1, char **cmd2)
{
	pid_t pid;
	int pipe_fd[2];

	if (pipe(pipe_fd) < 0)
		fatal("Could not open pipe in (fork_that)");
	pid = fork();
	if (pid == 0)
	{
		free_twod_arr(shell->cmds->args);
		shell->cmds->args = cmd2;
		dup_exec(shell, pipe_fd, STDIN_FILENO);
	}
	else
	{
		free_twod_arr(shell->cmds->args);
		shell->cmds->args = cmd1;
		dup_exec(shell, pipe_fd, STDOUT_FILENO);
	}
}

void pipeline(t_shell *shell)
{
	char **cmd_cpy;
	char **cmd1;
	char **cmd2;

	cmd_cpy = ft_copy_twod_arr(shell->cmds->args);
	cmd1 = get_before_pipe(cmd_cpy);
	cmd2 = get_after_pipe(cmd_cpy);
	free_twod_arr(cmd_cpy);
	fork_and_pipe(shell, cmd1, cmd2);

	// have the parent process write the first command through the pipe into the

	// child process


}