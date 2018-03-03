#include "../includes/libft.h"

void print_twod_arr(char **cmd)
{
	int i;

	i = 0;
	while (cmd[i])
	{
		ft_putendl(cmd[i]);
		i++;
	}
}