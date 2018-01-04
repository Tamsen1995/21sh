#include "../../includes/ft_sh.h"

/*
** the highest level of abstraction for
** the redirection module
*/


void redirections()
{
    


}

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

