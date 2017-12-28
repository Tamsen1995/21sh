#include "../../includes/ft_sh.h"

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
    line->prompt = "tamshell $> ";
    line->sz = get_win_size();
    line->cursor = init_cursor((int)line->sz->ws_col);
    line->first_c = get_first_c(line);
    line->current_c = line->first_c;
    line->last_c = line->first_c;
    tputs(tgetstr("vs", NULL), 0, putintc);
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
    ft_putstr(line->prompt);
    while (buf[0] != 10)
    {
        ft_bzero(buf, KEY_BUF_SIZE + 1);
        read(STDIN_FILENO, buf, KEY_BUF_SIZE);
        if (term_action(buf) == TRUE)
            check_input(line, buf);
        else if (term_action(buf) == FALSE)
            insert_buffer(line, buf);
        print_buffer(line);
        set_cursor(line);
    }

    // BUG : since the buffer line is still intact here something has to be wrong with the
    // stringify_buffer function.
    // Thus far I know that the way I output the buffer is not the source of the bug.
    // The bug could be either here or between here and the cmd_not_found function
    
    cmd_line = stringify_buffer(line->buffer);

    ft_putendl(""); // TESTING
    ft_putendl(cmd_line); // TESTING
    ft_putendl(""); // TESTING

    free_line_struct(line);
    return (cmd_line);
}
