#include "../../includes/ft_sh.h"


/*
** will discern the redirections 
** and then take everything not relevant for the execve
** function out of the commands array
*/

void 			discern_redirs(t_shell *shell)
{
	int i;
    char **cmd_args;

	i = 0;
    cmd_args = shell->cmds->args;
//////// WIP
	while (cmd_args[i])
	{

        //  if there is a redirection of output, AND the file it is pointing to exists and can be written towards
		if (ft_strcmp(cmd_args[i] , ">") == 0 && access(cmd_args[i + 1], W_OK) == 0)
            ft_putendl("File exists and can be written to"); // TESTING
		i++; // TESTING
	}

///////////

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