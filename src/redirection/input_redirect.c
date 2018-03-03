#include "../../includes/ft_sh.h"

static void fork_that(char **cmd, int fd_left, int fd_right)
{
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
	if (ft_strcmp(cmd[i], tmp) == 0)
		fd_left = c == R_INPUT ? STDIN_FILENO : STDOUT_FILENO;
	if ((fd_right = open(cmd[i + 1], o_flag, 0664)) == -1) // getting the fd of the file that is supposed to replace the initial fd
		fatal("Could not get fd in (do_redirect)");
	if (tmp) // if the redirection sign is still in tmp
	{
		cmd = ft_arrdelone(cmd, cmd[i + 1]); // deletes the the file whose fd is now inside of fd_right
		cmd = ft_arrdelone(cmd, tmp);		 // rid the cmds array of the redirection sign as well as
	}
}

// calls the do_redirect(cmd, R_INPUT, O_RDONLY, fork_that); function
// with the R_INPUT enum, some flags for the rights of the
void input_redirect(char **cmd)
{
	do_redirect(cmd, R_INPUT, O_RDONLY, fork_that);
}
