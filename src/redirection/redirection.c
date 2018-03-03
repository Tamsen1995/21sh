#include "../../includes/ft_sh.h"

/* 
** determines whether the given
** string is a redirection or not
*/
int is_redirection(char *s)
{
	char *ret;

	ret = NULL;

	if (s && ((ret = ft_strchr(s, R_OUTPUT)) ||
			  (ret = ft_strchr(s, R_OUTPUT_APPEND)) ||
			  (ret = ft_strchr(s, R_DUP_OUTPUT)) ||
			  (ret = ft_strchr(s, R_INPUT)) ||
			  (ret = ft_strchr(s, R_HERE_DOC)) ||
			  (ret = ft_strchr(s, R_DUP_INPUT)) ||
			  (ret = ft_strchr(s, R_PIPELINE))))
		return (*ret);
	return (FALSE);
}

// TODO : do_redirect function

// TODO : dup_it function

void output_redirect(char **cmd)
{
	print_twod_arr(cmd);									// TESTING
	ft_putstr("\n\n--->inside of output_redirect!!!!\n\n"); // TESTING
}


void output_append_redirect(char **cmd)
{
	print_twod_arr(cmd);											// TESTING
	ft_putstr("\n\n--->inside of output_append_redirect,!!!!\n\n"); // TESTING
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

// TODO : check for syntactical errors such as:
// a missing name for the redirect
// as well as an extraneous redirect after the redirect

static int got_redirection(char **cmd)
{
	int ret;
	int i;

	i = 0;
	ret = 0;
	while (cmd[i])
	{
		if ((ret = is_redirection(cmd[i])))
		{

			// TODO : error check and make sure the syntax for the redir is proper

			return (ret);
		}
		i++;
	}
	return (FALSE);
}

// TODO : implement enum which will indicate the various redirections
// TODO : implement a function which will
// return an enum that corresponds to one of these redirections

t_bool exec_redirection(char **cmd)
{
	int redirection_index;
	void (*const f[])(char **) = {
		output_redirect,
		output_append_redirect,
		input_redirect,
		// pipeline,
		// here_doc,
		// dup_input,
		// dup_output
	};

	if ((redirection_index = got_redirection(cmd)))
	{
		if (redirection_index != -1)
		{
			// The redirection index is the enum of
			// the redirection to be executed,
			// this index is subtracted by the R_OUTPUT
			// in order
			// to indicate the index of the
			// function to be taken to in the function array.
			f[redirection_index - R_OUTPUT](cmd);
		}
		return (TRUE);
	}
	return (FALSE);
}


