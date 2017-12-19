#include "../../includes/ft_sh.h"

/*
** checks the buffer linked list for actions which 
** might have to be executed
*/

void            check_input(t_line *line, char *buf) // WIP
{
    if (!line)
        fatal("Error (check_input)");
    if (!line->buffer || !buf)
        return ;
    cursor_movement(buf, line);
    // TODO other actions
}


struct winsize		*get_win_size()
{
    struct winsize *ret;

    if (!(ret = (struct winsize *)malloc(sizeof(struct winsize) * 1)))
        fatal("Can't allocate size struct (make_shell)");
    ioctl(0, TIOCGWINSZ, ret);

    // TODO: free ret
    return (ret);
}

/*
** initializes the struct necessary for line edition
*/

t_line         *init_line()
{
    t_line *line;

    line = NULL;
    if (!(line = malloc(sizeof(t_line) * 1)))
        fatal("");
    line->buffer = NULL;
    line->cursor = NULL;
    line->prompt = "tamsshell $> ";
    line->sz = get_win_size();
    line->cursor = init_cursor((int)line->sz->ws_col);
    line->first_c = get_first_c(line);
    return (line);
}

/*
** Display the initial contents of the text buffer on the screen.
** Get a keystroke from the user.
** If the keystroke is a command (like delete or backspace), dispatch or carry out that command.
** If the keystroke is a character, insert it into the text buffer (or replace the current character if not in insert mode).
** Display the updated contents of the text buffer on the screen.
*/

char            *prompt_loop(void)
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
        check_input(line, buf); // WIP
        if (term_action(buf) == FALSE) // WIP
        {
            ft_add_buf(&line->buffer, buf);
            print_buffer(line->buffer);
        }
    }
    cmd_line = stringify_buffer(line->buffer);

    // TODO free all of line here

    return (cmd_line);
}
