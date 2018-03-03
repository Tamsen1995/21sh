#include "../includes/libft.h"

/*
** receives and int and turns it into a string
*/

char *ft_int_to_str(int nbr)
{
	char *ret;

	ret = NULL;
	ret = ft_strnew(5);
	ft_bzero(ret, 5);
	ret[0] = nbr;

	return (ret);
}