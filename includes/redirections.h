#ifndef REDIRECTIONS_H
# define REDIRECTIONS_H

#include <unistd.h>


typedef struct		s_fds
{
	struct s_fds		*next;
    int                 fd;
}					t_fds;

#endif