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

t_string *get_here_doc_string_list(char *eof)
{
	char *buf;
	t_string *str_list;

	buf = NULL;
	str_list = NULL;
	while (ft_strcmp(buf, eof) != 0)
	{
		buf = here_prompt_loop(NULL);
		ft_strlst_push_back(&str_list, ft_strjoin(buf, "\n"));
		ft_strfree(buf);
	}
	return (str_list);
}

void here_doc(t_shell *shell)
{
	char *eof;
	t_string *str_list;
	char *here_doc_string;
	int i;

	i = 0;
	eof = NULL;
	str_list = NULL;
	here_doc_string = NULL;
	while (shell->cmds->args[i] && !ft_strchr(shell->cmds->args[i], R_HERE_DOC))
		i++;
	if (shell->cmds->args[i + 1])
		eof = shell->cmds->args[i + 1];
	str_list = get_here_doc_string_list(eof);
	shell->cmds->args = delete_redir_from_array(shell->cmds->args);
	here_doc_string = ft_stringify_strlst(str_list);
	fork_and_write(shell, STDIN_FILENO, here_doc_string);
}