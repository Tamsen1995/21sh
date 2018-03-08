#include "../includes/libft.h"

/*
** allocates a twod array with the indicated amount of memory
** already allocated for each array pointer
*/

char **ft_alloc_twod_arr_with_mem(int arr_len, int arr_ptrs_len)
{
	int i;
	char **ret;

	i = 0;
	ret = ft_alloc_twod_arr(arr_len + 1);
	while (i < arr_len)
	{
		ret[i] = ft_strnew(arr_ptrs_len);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}