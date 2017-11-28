#include "../includes/libft.h"

/*
** a function which will print 
** an error msg and then exit the program
*/

void fatal(char *err_msg)
{
    ft_putendl(err_msg);
    exit (-1);
}
