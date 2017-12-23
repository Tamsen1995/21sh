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
    return (line);
}


// TESTING
// Testing the buffer eveytime in order to see if desired elements have been executed
void           print_list_test(t_buf *buffer)
{
    t_buf *tmp;

    tmp = buffer;
    while (tmp)
    {
        ft_putstr(tmp->key);
        tmp = tmp->next;
    }
    exit(-1);
}


/*
** checks the buffer linked list for actions which 
** might have to be executed
*/

void            check_input(t_line **line, char *buf) // WIP
{
    if (!(*line))
        fatal("Error (check_input)");
    if (!(*line)->buffer || !buf)
        return ;
    cursor_movement(buf, (*line));

    if (ft_strcmp(buf, K_BACKSPACE) == 0)
    {
        del_buf_elem(line); // WIP


    }
    // TODO other actions
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
    int         buf_ind;
	char		buf[KEY_BUF_SIZE + 1];
    char        *cmd_line;
    t_line      *line;

    buf_ind = 0;
    line = init_line();
    tputs(tgetstr("vs", NULL), 0, putintc);
    ft_putstr(line->prompt);
    while (buf[0] != 10)
    {
        ft_bzero(buf, KEY_BUF_SIZE + 1);
        read(STDIN_FILENO, buf, KEY_BUF_SIZE);
        check_input(&line, buf); // WIP // edit the buffer according to action requested
        // the line comes out of check_input modified
        if (term_action(buf) == FALSE) // WIP
        {
            ft_add_buf(&line->buffer, buf, buf_ind);
            //print_buffer(line->buffer);
            line->current_c = line->current_c->next;
            line->last_c = line->last_c->next;
            buf_ind++;
        }
        print_buffer(line->buffer);
    }
    cmd_line = stringify_buffer(line->buffer);
    //free_line_struct(line);
    return (cmd_line);
}
