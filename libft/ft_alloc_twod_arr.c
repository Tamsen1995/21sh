#include "../includes/libft.h"

/*
** simply allocates an array of the indicated size
*/

char **ft_alloc_twod_arr(int size)
{
	char **ret;
	int i;

	i = 0;
	ret = NULL;
	if (!(ret = (char **)malloc(sizeof(char *) * size + 1)))
		fatal("Could not allocate inside of (ft_alloc_twod_arr)");
	while (i <= size)
	{
		ret[i] = NULL;
		i++;
	}
	return (ret);
}