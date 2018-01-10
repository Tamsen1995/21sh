#ifndef REDIRECTIONS_H
# define REDIRECTIONS_H

#include <unistd.h>
#include "../includes/structs.h"


t_tokens            *lexer(char **cmd_line);


void        		parser(t_shell *shell);
int				    ft_get_fd(char *file); // TODO : implement and put into libft.
// every fd that is acquired with this function needs to be closed

#endif