#include "../../includes/ft_sh.h"

void pipeline(t_shell *shell)
{
	print_twod_arr(shell->cmds->args);
	exit(-1);
}