#ifndef REDIRECTIONS_H
# define REDIRECTIONS_H

#include <unistd.h>
#include "../includes/structs.h"


t_ast_node			*make_ast(t_tokens *tokens);
int					ft_find_operator(t_tokens *tokens);

t_tokens            *lexer(char **cmd_line);
void        		parser(t_shell *shell);
int				    ft_get_fd(char *file); // TODO : implement and put into libft.
// every fd that is acquired with this function needs to be closed

#endif