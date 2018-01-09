#ifndef REDIRECTIONS_H
# define REDIRECTIONS_H

#include <unistd.h>

enum					e_redir
{
	IN,
	OUT,
	ERR,
	NO_REDIR
};

enum					e_tokentype
{
	SEMI_COL,
	ND_OR,
	PIPE,
	INPUT_RE,
	OUTPUT_RE,
	ERR_RE,
	TXT_CMD
};

typedef struct		s_fds
{
	struct s_fds		*next;
    int                 fd;
}					t_fds;

typedef struct			s_token
{
	struct s_fds		*next;
	enum e_tokentype	tok_type;
	char				*token;
}						t_token;

void		        add_fd(t_fds **begin_list, char *file_name);
t_fds		        *ft_new_fd(char *file_name);
int				    ft_get_fd(char *file); // TODO : implement and put into libft.
// every fd that is acquired with this function needs to be closed

#endif