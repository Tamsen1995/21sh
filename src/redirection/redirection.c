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

/*
** Since pipes get priority, 
** I need to check for a pipe after redirection
*/

t_bool got_pipe_after_dup(char **cmd)
{
	int i;
	t_bool got_dup;

	i = 0;
	got_dup = FALSE;
	while (cmd[i])
	{
		if (ft_strchr(cmd[i], R_PIPELINE) && got_dup == TRUE)
			return (TRUE);
		else if (ft_strchr(cmd[i], R_DUP_INPUT) || ft_strchr(cmd[i], R_DUP_OUTPUT))
			got_dup = TRUE;
		else if (is_redirection(cmd[i]))
			return (FALSE);
		i++;
	}
	return (FALSE);
}



/*
** it also checks for a possible missing redirect parameter
*/

t_bool redir_has_fd_right(char **cmd)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (cmd[i])
	{
		if ((ret = is_redirection(cmd[i])) && cmd[i + 1])
			return (TRUE);
		i++;
	}
	ft_putendl("tamshell\t:\tparsing error near newline");
	return (FALSE);
}

// TODO : got_redirection function
// got_redirection returns the redirection index which determines the
// redirection that is supposed to take place.
// it does so by checking for a pipeline
// and also checks for syntax errors
// once a redirection has been found


// TODO : check for syntactical errors such as:
// as well as an extraneous redirect after the redirect

int got_redirection(char **cmd)
{
	int ret;
	int i;

	i = 0;
	ret = 0;
	if (got_pipe_after_dup(cmd))
		return (R_PIPELINE);
	while (cmd[i])
	{
		if ((ret = is_redirection(cmd[i])))
			return (ret);
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
		here_doc,
		dup_input,
		dup_output,
	};
	if ((redirection_index = got_redirection(shell->cmds->args)))
	{
		if (redirection_index != -1)
			f[redirection_index - R_OUTPUT](shell);
		return (TRUE);
	}
	return (FALSE);
}
