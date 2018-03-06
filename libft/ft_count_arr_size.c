#include "../includes/libft.h"

/*
** evaluates the length of a twod array
*/

int	ft_count_arr_size(char **array)
{
	int i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}