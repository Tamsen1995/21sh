#include "../../includes/ft_sh.h"


void        modify_buffer(t_line *line, char *buf)
{
    if (term_action(buf) == TRUE)
        check_input(line, buf);
    else if (term_action(buf) == FALSE)
        insert_buffer(line, buf);
}

/*
** Display the initial contents of the text buffer on the screen.
** Get a keystroke from the user.
** If the keystroke is a command (like delete or backspace), dispatch or carry out that command.
** If the keystroke is a character, insert it into the text buffer (or replace the current character if not in insert mode).
** Display the updated contents of the text buffer on screen.
*/

char            *prompt_loop(t_hist *history)
{
	char		buf[KEY_BUF_SIZE + 1];
    char        *cmd_line;
    t_line      *line;

    line = init_line(history);
    ft_putstr(line->prompt);
    while (ft_strcmp(buf, K_RETURN) != 0)
    {
        ft_bzero(buf, KEY_BUF_SIZE + 1);
        read(STDIN_FILENO, buf, KEY_BUF_SIZE); 
        modify_buffer(line, buf);
        print_buffer(line);
    }
    cmd_line = stringify_buffer(line->buffer);
    free_line_struct(line);
    return (cmd_line);
}
