#include "../../includes/ft_sh.h"

/*
** resets all modified file descriptors
** usually to be executed right after
** the execution of each command
*/

void        reset_redirects()
{

}

/*
** will discern the redirections 
** and then take everything not relevant for the execve
** function out of the commands array
*/

void 			discern_redirs(t_shell *shell)
{
	int i;

	i = 0;
	
	while (shell->cmds->args[i])
	{
		ft_putendl(shell->cmds->args[i]);
		i++; // TESTING
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



// bash processes redirections from left to right 

// pointing the stdout towards a file with >file and then the stderr towards the stdout 2>&1
// will result in both being pointed towards the file.
// however pointing the stderr towards the stdout and then the stdout towards the file will not result in the same thing
    // in other words, the pointers pointing to an adress of an fd are not modified along with the fd address itself. 
    // Only whenever the pointer is set. So if an fd pointer is set to a certain modified fd, and another pointer decides to point to it, 
    // then it will also point to the modified address. But if a pointer is set to another fd pointer, and that pointer is modified, 
    // the pointer pointing to it will not be modified, but will remain at its initial address 
    // (huge run on sentence)


// writing command n>file will redirect the fd n to file

// once the redirection has been executed I oughta reset everything back to normal so that
// the shell may continue to print its input in a normal manner

// The command structure will be expanded
// Additional fields for input files, and output files
// are to be added.
// (REDIRECTIONS)


// < infile

// > outfile

// Perhaps for every command one needs to discern the
// fd through the redirections. Once this is done the command
// can be executed as usual
    // So for every command the outfile, infile, and errfile
    // will be determined through variables
    // if no changes have been made to either of these, they remain
    // NULL and all outputs/inputs will be treated normally

// > creating overwriting
    // only redirectos stdout
    // stderr is not considered

// >> appending to a file

// < inputting a file into something, usually and in most cases 
    // the stdin of a command

// 2>&1 implies that the stderr is being sent to the same place
    // as stderr

// 2> redirects the stderr to whereever it makes sense

// | this is a pipe and it redirects the stdout of one file to the stdin
    // of another

// The redirections module mainly takes care of the manipulation of file descriptors

