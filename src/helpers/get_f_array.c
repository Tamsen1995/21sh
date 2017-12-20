#include "../../includes/ft_sh.h"

/*

This function shall return an array of function pointers
which will return the function that is to execute the 
action asked for, such as cursor movement

static void		*get_f_array(void)
{
	static enum e_status	(*f[])(char *) = {
		clear_term,
		del,
		backspace,
		copy,
		cut_forward,
		cut_backward,
		paste,
		move_left,
		move_right,
		move_up,
		move_down,
		move_begin,
		move_end,
		move_next_word,
		move_prev_word,
		set_history,
		get_history,
		insert,
		NULL
	};

	return ((void *)f);
}

*/