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

			// TODO : error check and make sure the syntax
			// for the redir is properly checked,
			// if it isn't throw an error to the console

			return (ret);
		}
		i++;
	}
	return (FALSE);
}

t_bool exec_redirection(t_shell *shell)
{
	int redirection_index;
	void (*const f[])(t_shell *) = {
		output_redirect,
		output_append_redirect,
		input_redirect,
		pipeline,
		// here_doc,
		// dup_input,
		// dup_output
	};

	if ((redirection_index = got_redirection(shell->cmds->args)))
	{
		if (redirection_index != -1)
			f[redirection_index - R_OUTPUT](shell);
		return (TRUE);
	}
	return (FALSE);
}
