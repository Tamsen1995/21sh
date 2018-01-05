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
** parses the command line which will include redirections (>, <, &)
** and then assigns new fds to the list element, 
** or leaves them at their standard value
*/

void        discern_new_fds(t_shell *shell)
{
    if (!shell)
        fatal("Error (discern_new_fds)");

    // parse_cmd_line();     
    // get fds of all the files  in the command list
    // have an array returned

    // assign_cmd_fds(); // 
    // discern whether these fds are so supposed to be taken from or outputted to, by checking the redirection symbol before
    // assign the fds to the appropiate int arrays in the cmds struct according to the redirection symbols before them. 

    // if one of the std fds is to be set to another one, 
    // then one has to check if the fd doesn't already belong to something else
    // if so make the fd to be modified to that fd as well

    // since several fds can be inputted from or outputted to, instead of merely an int per command, I'll need an array of ints
}


/*
** the highest level of abstraction for
** the redirection module
*/


void        redirections(t_shell *shell)
{
    // TODO : implement
    if (!shell)
        fatal("Error (redirections)");
    
    
    // discern the new fds for the individual commands
    //  discern_new_fds(shell);

    // if you want to use stdin later in your program again, 
    // then you'll have to save the stdin in a variable.
    // dup(0); will return this ?
    
    // find out the file descriptors of all files in in the command struct

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

