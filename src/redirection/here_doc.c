#include "../../includes/ft_sh.h"

char *here_prompt_loop(t_hist *history)
{
	char buf[KEY_BUF_SIZE + 1];
	char *cmd_line;
	t_line *line;

	line = init_line(history);
	ft_putstr("h e r edoc> ");
	ft_bzero(buf, KEY_BUF_SIZE + 1);
	while (ft_strcmp(buf, K_RETURN) != 0)
	{
		ft_bzero(buf, KEY_BUF_SIZE + 1);
		read(STDIN_FILENO, buf, KEY_BUF_SIZE);
		modify_buffer(line, buf);
		print_buffer(line);
	}
	cmd_line = stringify_buffer(line->buffer);
	free_line_struct(line);
	return (cmd_line);
}

char **delete_redir_from_array(char **cmds)
{
	char **ret;
	t_string *str_list;
	int i;
	int k;

	i = 0;
	k = 0;
	str_list = NULL;
	ret = ft_alloc_twod_arr(ft_count_arr_size(cmds));
	while (cmds[i] && !ft_strchr(cmds[i], R_HERE_DOC))
		i++;
	while (cmds[k])
	{
		if (ft_strcmp(cmds[k], cmds[i]) != 0 && ft_strcmp(cmds[k], cmds[i + 1]) != 0)
			ft_strlst_push_back(&str_list, cmds[k]);
		k++;
	}
	ret = ft_list_to_arr(str_list);
	free_twod_arr(cmds);
	return (ret);
}

/*
** inserts the here_doc string into the command array
*/

// void insert_heredoc_str()
// {

// 	ft_stringify_strlst(str_list);
// }

void here_doc(t_shell *shell)
{
	char *buf;
	char *eof;
	t_string *str_list;
	int i;

	i = 0;
	buf = NULL;
	eof = NULL;
	str_list = NULL;
	while (shell->cmds->args[i] && !ft_strchr(shell->cmds->args[i], R_HERE_DOC))
		i++;
	if (shell->cmds->args[i + 1])
		eof = shell->cmds->args[i + 1];

	while (ft_strcmp(buf, eof) != 0)
	{
		buf = here_prompt_loop(NULL);
		ft_strlst_push_back(&str_list, buf);
		ft_strfree(buf);
	}
	shell->cmds->args = delete_redir_from_array(shell->cmds->args);


	//	shell->cmds->args = insert_heredoc_str(shell->cmds->args, str_list);

	print_twod_arr(shell->cmds->args); // TESTING



	// at the end stringify the entire list

	// TODO :

	// and feed it into the program to be executed

	// delete the redirection symbol and the eof args out of the cmd array
	// insert the string into the cmd array
	exit(-1); // TESTING
}