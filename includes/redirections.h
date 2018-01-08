#ifndef REDIRECTIONS_H
# define REDIRECTIONS_H

#include <unistd.h>


typedef struct		s_in_fd
{
	struct s_in_fd		*next;
    int                 fd;
}					t_in_fd;

#endif