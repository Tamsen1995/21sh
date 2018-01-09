#ifndef REDIRECTIONS_H
# define REDIRECTIONS_H

#include <unistd.h>


typedef struct		s_fds
{
	struct s_fds		*next;
    int                 fd;
}					t_fds;


/*
** enum
*/

enum					e_redir
{
	INPUT_RE,
	OUTPUT_RE,
	ERR_RE,
	NO_REDIRECTION
};

void		        add_fd(t_fds **begin_list, char *file_name);
t_fds		        *ft_new_fd(char *file_name);
int				    get_fd(char *file);

#endif