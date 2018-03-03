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

// TODO : input_redirect function

// calls the do_redirect(cmd, R_INPUT, O_RDONLY, fork_that); function
// with the R_INPUT enum, some flags for the rights of the
void input_redirect(char **cmd)
{
	ft_putstr("\n\n--->inside of input_redirect!!!!\n\n"); // TESTING
	// Test case for this function
	// will be to print out the cmd array.

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
		ft_putnbr(cmd[i][0]);
		if ((ret = is_redirection(cmd[i])))
		{

			ft_putnbr(ret); // TESTING this should
			// print an index number whenever a redirection has been inputted
			// but it's not even going into this if condition
			// TODO : FIX

			ft_putstr("\n\n--++->inside of got_redirection's if condition meaning a redirection was found.\n\n"); // TESTING

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
		// output_redirect,
		// output_append_redirect,
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
			ft_putnbr(redirection_index - R_OUTPUT); // TESTING
			f[redirection_index - R_OUTPUT](cmd);
		}
		return (TRUE);
	}
	return (FALSE);
}

/*
** reassigns redirections inside of the cmds array
** so that they may match with the enums 
** defined inside the header
*/

char **assign_redirections(char **cmd)
{
	int i;
	char **ret_cmd;

	i = 0;
	ret_cmd = NULL;
	if (!cmd)
		fatal("Error in (assign_redirections)");
	ret_cmd = ft_alloc_twod_arr(ft_count_arr_size(cmd));
	while (cmd[i])
	{
		if (ft_strcmp(cmd[i], "<"))
			ret_cmd[i] = ft_int_to_str(R_INPUT);
		else
			ret_cmd[i] = ft_strdup(cmd[i]);
		i++;
	}
	free_twod_arr(cmd);
	return (ret_cmd);
}
