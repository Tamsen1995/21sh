#include "../../includes/ft_sh.h"

/*
** so far only a place to tinker with the
** process of redirection
*/

void exec_redirections(t_shell *shell)
{
    // TODO : research
    // TODO : check the incoming commands (shell->cmds) for potential redirection

    if (!shell)
        fatal("Error (exec_redirection)");
	int fd1 = open("textfile.txt", O_CREAT | O_WRONLY | O_TRUNC);
    dup2(fd1, STDOUT_FILENO); 
    // whatever's supposed to go into the second FD is going into the first one
	close(fd1);
}
