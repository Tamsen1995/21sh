#include "../../includes/ft_sh.h"

void dup_exec(char **cmd, int *pipe_fd, int fd_left)
{
	int save_fd;

	cmd  = NULL;// TESTING

	save_fd = dup(fd_left);
	close(pipe_fd[fd_left == STDOUT_FILENO ? 0 : 1]); // closing write end because this process will only read from the pipe
	dup2(pipe_fd[fd_left == STDOUT_FILENO ? 1 : 0], fd_left);
	close(pipe_fd[fd_left == STDOUT_FILENO ? 1 : 0]);

	// execute command recursively

	// make the fd_left into the save_fd (its initial value) again

	// close the save fd

	// make the process wait or exit

	// 	exec_cmd(cmd);
	// dup2(save_fd, fd_left);
	// close(save_fd);
	// fd_left == STDOUT_FILENO ? (void)wait(NULL) : exit(EXIT_SUCCESS);

	// closes the fd left

	//
}

/*
** forks the process so that the parent may write from the fd_right into the pipe
** the child process will READ from the pipe and then 
** execute the command with this pipe set up
*/

static void fork_that(char **cmd, int fd_left, int fd_right)
{
	pid_t pid;
	pid_t wpid;
	int status;
	int pipe_fd[2];

	fd_left = 0;  // TESTING
	fd_right = 0; // TESTING
	cmd = NULL; // TESTING

	if (pipe(pipe_fd) < 0)
		fatal("Could not open pipe in (fork_that)");
	pid = fork();
	if (pid == 0)
	{
		// replace the fd_left with the read end of the pipe
		// set the child process up to read from the reading end of the pipe
	}
	else if (pid < 0)
		fatal("Child procress could not be created (sh_launch)");
	else
	{
		// write to the pipe with the fd_right
		wpid = waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			wpid = waitpid(pid, &status, WUNTRACED);
	}
}

// TEST function
int get_fd(char *s)
{
	int fd;

	if (!s)
		return (-1);
	while (*s && !ft_isdigit(*s) && *s != '-')
		s++;
	if (!*s)
		return (-1);
	fd = ft_atoi(s);
	return (fcntl(fd, F_GETFD) ? -1 : fd);
}

/*
** finds the fd to be replaced 
** finds the fd that is supposed to replace
** stores these in two seperate variables (fd_left and fd_right)
** deletes the redirection symbol as well as the redirection file from the cmds array
*/

void do_redirect(char **cmd, enum e_replacement c, int o_flag, void (*do_stuff_with_cmd_and_fd_now)(char **, int, int))
{
	int i;
	char *tmp;
	int fd_left;
	int fd_right;

	i = 0;
	fd_left = 42; // TESTING
	while (cmd[i] && !(tmp = ft_strchr(cmd[i], c)))
		i++;
	if ((ft_strcmp(cmd[i], tmp) == 0) || (fd_left = get_fd(cmd[i])) == -1)
		fd_left = c == R_INPUT ? STDIN_FILENO : STDOUT_FILENO;
	if ((fd_right = open(cmd[i + 1], o_flag, 0664)) == -1) // getting the fd of the file that is supposed to replace the initial fd
		fatal("Could not get fd in (do_redirect)");
	if (tmp) // if the redirection sign is still in tmp
	{
		cmd = ft_arrdelone(cmd, cmd[i + 1]); // deletes the the file whose fd is now inside of fd_right
		cmd = ft_arrdelone(cmd, tmp);		 // rid the cmds array of the redirection sign as well as
	}

	do_stuff_with_cmd_and_fd_now(cmd, fd_left, fd_right);
}

// calls the do_redirect(cmd, R_INPUT, O_RDONLY, fork_that); function
// with the R_INPUT enum, some flags for the rights of the
void input_redirect(char **cmd)
{
	do_redirect(cmd, R_INPUT, O_RDONLY, fork_that);
}
