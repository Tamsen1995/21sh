
#include "../includes/ft_sh.h"



void sig_handl(int sig)
{
	t_shell *shell;

	shell = get_shell();
	if (sig == SIGINT)
		sh_loop(shell);

}

void signals(void)
{
	signal(SIGINT, sig_handl);
	signal(SIGWINCH, sig_handl);
	signal(SIGINFO, sig_handl);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}