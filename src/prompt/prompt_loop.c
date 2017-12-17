#include "../../includes/ft_sh.h"

/*
** checks the buffer linked list for actions which 
** might have to be executed
*/

void            check_input(t_buf *buffer, char *buf) // WIP
{
    t_buf *tmp;
     // the action keys for the line
    // editing such as the arrow keys

    tmp = NULL;
    if (!buffer || !buf)
        return ;
    tmp = buffer;
    cursor_movement(buf, buffer);
    // TODO other actions
}


t_line         *init_line()
{
    t_line *line;

    line = NULL;
    if (!(line = malloc(sizeof(t_line) * 1)))
        fatal("");
    line->buffer = NULL;
    line->cursor = NULL;
    line->prompt = "tamsshell $> ";
    line->prompt_len = ft_strlen(line->prompt);
    return (line);
}

/*
** Display the initial contents of the text buffer on the screen.
** Get a keystroke from the user.
** If the keystroke is a command (like delete or backspace), dispatch or carry out that command.
** If the keystroke is a character, insert it into the text buffer (or replace the current character if not in insert mode).
** Display the updated contents of the text buffer on the screen.
*/

char            *prompt_loop(void) // WIP
{

	char		buf[KEY_BUF_SIZE + 1];
    char        *cmd_line;
    t_line      *line;

    line = init_line();
    tputs(tgetstr("vs", NULL), 0, putintc);
    ft_putstr(line->prompt);
    while (buf[0] != 10)
    {
        ft_bzero(buf, KEY_BUF_SIZE + 1);
        read(STDIN_FILENO, buf, KEY_BUF_SIZE);
        // edit the buffer according to action requested
        check_input(line->buffer, buf); // WIP
        if (term_action(buf) == FALSE) // WIP
            ft_add_buf(&line->buffer, buf);
        if (term_action(buf) == FALSE) // WIP
            print_buffer(line->buffer);
    }
    cmd_line = stringify_buffer(line->buffer);
    // get_next_line(0, &buf); 
    return (cmd_line);
}
