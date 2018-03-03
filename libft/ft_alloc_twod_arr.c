#include "../includes/libft.h"

/*
** simply allocates an array of the indicated size
*/

char **ft_alloc_twod_arr(int size)
{
	char **ret;

	ret = NULL;
	if (!(ret = (char **)malloc(sizeof(char *) * size + 1)))
		fatal("Could not allocate inside of (ft_alloc_twod_arr)");
	return (ret);
}