#include "../includes/libft.h"

/*
** returns an array identical to the one it received
*/

char **ft_copy_twod_arr(char **array)
{
	int len;
	char **ret;

	len = 0;
	while (array[len])
		len++;
	if (!(ret = (char **)malloc(sizeof(char *) * len + 1)))
		fatal("Could not allocate (ft_copy_twod_arr)");
	len = 0;
	while (array[len])
	{
		ret[len] = ft_strdup(array[len]);
		len++;
	}
	ret[len] = NULL;
	return (ret);
}
