#include "../../includes/ft_sh.h"

// TODO: properly implement
/*

void			switch_term(void)
{
	char					term_buf[2048];
	struct termios			term;
	static struct termios	*old_term = NULL;

	if (tcgetattr(STDIN_FILENO, &term))
		error(E_GETATTR, NULL);
	if (!old_term && (old_term = (struct termios *)malloc(sizeof(term))))
		ft_memcpy(old_term, &term, sizeof(struct termios));
	else
	{
		tputs(tgetstr("ei", NULL), 0, tputs_output);
		if (tcsetattr(STDIN_FILENO, 0, old_term))
			error(E_SETATTR, NULL);
		old_term ? ft_memdel((void *)&old_term) : (void)0;
		return ;
	}
	term.c_lflag &= (unsigned int)~(ICANON);
	term.c_lflag &= (unsigned int)~(ECHO);
	term.c_cc[VTIME] = 0;
	term.c_cc[VMIN] = 1;
	if (tcsetattr(STDIN_FILENO, TCSADRAIN, &term))
		error(E_SETATTR, NULL);
	if (tgetent(term_buf, getenv("TERM")) == ERR)
		error(E_TERM, NULL);
	tputs(tgetstr("im", NULL), 0, tputs_output);
}

*/