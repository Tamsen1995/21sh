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

////////////////// CURSOR ACTIONS



/*
** allocates a new cursor list element
*/

t_cursor      *ft_new_cur(void)
{
    t_cursor *new;

    if (!(new = (t_cursor *)malloc(sizeof(t_cursor))))
        fatal("Error: could not allocate env var list elem in ft_new_env");
    new->next = NULL;
    new->prev = NULL;
    new->cursor = FALSE;
    return (new);
}

/*
** pushes a cursor element to the end of a list
*/

void		ft_add_cursor(t_cursor **begin_list)
{
    t_cursor *tmp;

    tmp = NULL;
	if (!*begin_list)
	{
		*begin_list = ft_new_cur();
		return ;
	}
    else
    {
        tmp = *begin_list;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = ft_new_cur();
        tmp->next->prev = tmp;
    }
}

/*
** returns a linked list which will be used to keep track
** of the cursor
** each list element represents a potential cursor position
** the length of the list will be that of the columns 
** within the temrinal window
*/

t_cursor       *init_cursor(int win_size) // WIP
{
    int i;
    t_cursor *cur_list;

    i = 0;
    cur_list = NULL;
    if (!win_size)
        fatal("Error (init_cursor)");
    while (i < win_size)
    {
        ft_add_cursor(&cur_list);
        i++;
    }
    return (cur_list);
}

////////////////// CURSOR ACTIONS

// TESTING purposes
void           test_cursor(t_line *line)
{
    int i;
    t_cursor *tmp;

    i = 0;
    tmp = line->cursor;
    printf("\n\n - > %d\n\n", line->sz->ws_col);
    while (tmp)
    {
        i++;
        tmp = tmp->next;
    }
    printf("\n\n - > %d\n\n", i);
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
    line->sz = get_win_size();
    line->cursor = init_cursor((int)line->sz->ws_col);
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
