#include "../includes/libft.h"

/*
** takes an array and a string and then deletes
** the string out of the array 
** (only does so with the first instance of said string)
** returns a copy of said array without the indicated string
*/
char **ft_arrdelone(char **arr, char *del_str)
{
	int i;
	int k;
	char **ret;

	i = 0;
	k = 0;
	ret = ft_alloc_twod_arr(ft_count_arr_size(arr));
	while (arr[i])
	{
		if (ft_strcmp(arr[i], del_str) != 0)
		{
			ret[k] = ft_strdup(arr[i]);
			k++;
		}
		i++;
	}
	free_twod_arr(arr);
	return (ret);
}