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
    line->prompt = "tamshell $> ";
    line->sz = get_win_size();
    line->cursor = init_cursor((int)line->sz->ws_col);
    line->first_c = get_first_c(line);
    line->current_c = line->first_c;
    line->last_c = line->first_c;
    return (line);
}


////////////////////////////////////////// INSERT / DELETE in relation to current cursor position


// find the buffer element at which the cursor is currently positioned at
    // go to the current_c
        // count the number of jumps/iterations in the process
    // jump / iterate said number of times in the buffer
        // boom ! you've got the desired buffer position into which you can insert/delete


/*
** returns the buffer element which is found at the current tracked cursor position
*/





// TODO delete
    // find buffer/cursor position
    // delete element before the buffer/cursor position
        // take the elem to be deleted
        // point the next pointer of the prev pointer to the next pointer
        // point the prev pointer of the next pointer to the prev pointer
        // free/delete elem

/*
** deletes the element before the current cursor position in the buffer
*/

void           del_buf_elem(t_line *line);



// TODO insert

////////////////////////////////////////// INSERT / DELETE in relation to current cursor position

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
        check_input(line, buf); // WIP // edit the buffer according to action requested
        if (term_action(buf) == FALSE) // WIP
        {
            ft_add_buf(&line->buffer, buf); // I might have to heavily modify this in order for it to insert the desired keys at the current_c position
            // everytime a new key is added to the buf, 
            // the last possible cursor position shall move as well


            print_buffer(line->buffer);
            line->current_c = line->current_c->next;
            line->last_c = line->last_c->next;
        }
    }
    cmd_line = stringify_buffer(line->buffer);
    free_line_struct(line);
    return (cmd_line);
}
