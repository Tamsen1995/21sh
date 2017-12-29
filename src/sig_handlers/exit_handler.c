#include "../../includes/ft_sh.h"

/*
** resets the shell settings
*/

void            sel_mode_off(t_shell *shell)
{
	tcsetattr(0, TCSADRAIN, shell->termold);
	tputs(tgetstr("te", NULL), 1, putintc);
	tputs(tgetstr("ve", NULL), 1, putintc);
}

void                exit_handler()
{
    t_shell *shell;

    shell = get_shell();
    free_shell(shell); // TESTING
    sel_mode_off(shell);
    exit(0);

}
