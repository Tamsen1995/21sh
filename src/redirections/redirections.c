#include "../../includes/ft_sh.h"

/*
** resets all modified file descriptors
** usually to be executed right after
** the execution of each command
*/

void reset_redirects()
{
    // TODO : implement
}

/*
** the highest level of abstraction for
** the redirection module
*/


void redirections()
{
    // TODO : implement


}

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

