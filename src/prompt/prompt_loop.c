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
    if (!buffer)
        return ;
    tmp = buffer;

    cursor_movement(buf, buffer);
    // TODO other actions
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
    t_buf       *buffer;

    buffer = NULL;

    tputs(tgetstr("vs", NULL), 0, putintc);

    // if the buffer equals
    // to enter which is 10
    ft_putstr("tamshell$> ");
    while (buf[0] != 10)
    {
        ft_bzero(buf, KEY_BUF_SIZE + 1);
        read(STDIN_FILENO, buf, KEY_BUF_SIZE);


        // edit the buffer according to action requested
        check_input(buffer, buf); // WIP
        if (term_action(buf) == TRUE) // WIP
            ft_add_buf(&buffer, buf);
        


        // print the edited buffer
        print_buffer(buffer);

        // ft_putstr(buf); // TESTING
        // tputs(tgetstr("ll", NULL), 0, putintc);

        // somewhere here I need to check for input
        // to see if there is an arrow key  I need to be able
        // to read. This will constitute for the cursor movement

        // The output of the user's input shall be made here
        // if there is any kind of cursor movement then the cursor on the screen shall move
    }
    cmd_line = stringify_buffer(buffer);
    // get_next_line(0, &buf); 
    return (cmd_line);
}
