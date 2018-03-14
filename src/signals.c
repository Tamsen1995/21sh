
#include "../includes/ft_sh.h"
#include <signal.h>

pid_t g_pid;

void sig_handl(int sig)
{
	t_shell *shell;
	t_hist *tmp; // TESTING

	tmp = NULL;
	shell = get_shell();
	if (sig == SIGINT)
	{
		if (!g_pid)
		{
			get_line(NULL);
			ft_putendl("");
			ft_putstr("tamshell $> ");
		}
		else
			ft_putstr("You too");
	}
}

void signals(void)
{
	signal(SIGINT, sig_handl);
	signal(SIGWINCH, sig_handl);
	signal(SIGINFO, sig_handl);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}