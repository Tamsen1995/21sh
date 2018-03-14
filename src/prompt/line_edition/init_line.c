#include "../../../includes/ft_sh.h"

struct winsize *get_win_size()
{
    struct winsize *ret;

    if (!(ret = (struct winsize *)malloc(sizeof(struct winsize) * 1)))
        fatal("Can't allocate size struct (make_shell)");
    ioctl(0, TIOCGWINSZ, ret);

    // TODO: free ret
    return (ret);
}

t_line *get_line(void)
{
    static t_line *line = NULL;

    if (line == NULL)
        line = init_line();
    else
    {
        free_buffer(line->buffer);
        line->buffer = NULL;
        line->sz = get_win_size();
        line->cursor = init_cursor((int)line->sz->ws_col);
        line->first_c = get_first_c(line);
        line->current_c = line->first_c;
        line->last_c = line->first_c;
        line->his_index = 0;
    }

    return (line);
}

/*
** initializes the struct necessary for line edition
*/

t_line *init_line()
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
    line->his_index = 0;
    tputs(tgetstr("vs", NULL), 0, putintc);
    return (line);
}
