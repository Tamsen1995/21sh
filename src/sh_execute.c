#include "../includes/ft_sh.h"



// TODO : do_redirect function

// TODO : dup_it function


// TODO : input_redirect function

// calls the do_redirect(cmd, R_INPUT, O_RDONLY, fork_that); function
// with the R_INPUT enum, some flags for the rights of the 
void            input_redirect(char **cmd)
{
    cmd = NULL; // TESTING purposes

}

// TODO : got_redirection function

// finds a redirection within the cmd array
// and returns an index nbr assigned to the function of
// said redirection

// got_redirection returns the redirection index which determines the
// redirection that is supposed to take place.
// it does so by checking for a pipeline
// and also checks for syntax errors
// once a redirection has been found
// it also checks for a possible missing redirect parameter
// file


static int got_redirection(char **cmd)
{
    int ret;
    int i;

    i = 0;
    ret = 0; // ret is to be the number of the redirect 
    // index which is to be returned from this function later on
    while (cmd[i])
    {
        ft_putendl(cmd[i]);
        i++;
    }

    return (FALSE);
}



// TODO : implement enum which will indicate the various redirections
// TODO : implement a function which will 
// return an enum that corresponds to one of these redirections

void			exec_redirection(char **cmd)
{
	int		redirection_index;
	// void	(*const f[])(char **) = {
	// 		input_redirect,
	// };

	if ((redirection_index = got_redirection(cmd)))
	{

        ft_putnbr(redirection_index); // TESTING

		// if (redirection_index != -1)
		// {
		// 	// The redirection index is the enum of 
		// 	// the redirection to be executed,
		// 	// this index is subtracted by the R_OUTPUT
		// 	// in order 
		// 	// to indicate the index of the 
		// 	// function to be taken to in the function array.
		// 	f[redirection_index - R_OUTPUT](cmd);
		// }
		// return (TRUE);
	}
	// return (FALSE);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*
** function that will either start a process or a builtin
*/

int sh_execute(char **envv, t_shell *shell)
{
    if (!shell->cmds->args || !shell->cmds->args[0])
        return (1);

    //  TODO : implement a redirection flow (input first)


    exec_redirection(shell->cmds->args); // WIP
    // this function will redirect the flow towards a redirections execution.



    exit(-1); // TESTING


    if (check_builtins(shell->cmds->args[0]) == TRUE ||
        check_builtin_path(shell) == TRUE)
        return (exec_builtin(shell));


        
    return (sh_launch(envv, shell));
}

