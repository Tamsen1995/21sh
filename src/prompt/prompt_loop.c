#include "../../includes/ft_sh.h"

/*
** allocates a new environment variables list element
*/

t_buf      *ft_new_buf(char *key)
{
    t_buf *new;

    if (!(new = (t_buf *)malloc(sizeof(t_buf))))
        fatal("Error: could not allocate env var list elem in ft_new_env");
    new->next = NULL;
    new->prev = NULL;
    new->key = NULL;
    new->cursor = TRUE;
    new->key = ft_strdup(key);
    return (new);
}

/* 
** iterates to the end of the cmd list
** and then adds the value to it
*/

void		ft_add_buf(t_buf **begin_list, char *key)
{
    t_buf *tmp;

    tmp = NULL;
	if (!*begin_list)
	{
		*begin_list = ft_new_buf(key);
		return ;
	}
    else
    {
        tmp = *begin_list;
        while (tmp->next)
            tmp = tmp->next;
        tmp->cursor = FALSE;
        tmp->next = ft_new_buf(key);
        tmp->next->prev = tmp;
    }
}


/*
** iterates through an entire list
** and finds out the length of it
*/

int         list_len(t_buf *buffer)
{
    int     i;
    t_buf   *tmp;

    i = 0;
    tmp = NULL;
    if (!buffer)
        fatal("error in (list_len)");
    tmp = buffer;
    while (tmp)
    {
        i++;
        tmp = tmp->next;
    }
    return (i);
}

/*
** stringifies the linked list of commands
*/

char        *stringify_buffer(t_buf  *buffer)
{
    char    *ret;
    int     i;
    t_buf   *tmp;

    ret = NULL;
    tmp = NULL;
    i = 0;
    if (buffer == NULL)
        fatal("error in (stringify_buffer)");
    i = list_len(buffer);
    ret = ft_strnew(i); // allocating a new string
    tmp = buffer;
    while (tmp->next) // iteratively concatenate the string
    {
        ret = ft_strcat(ret, tmp->key);
        tmp = tmp->next;
    }
    return (ret);
}



// This is a function pointer which shall point
// to the move left function
void (*p_move_left)(t_buf *buffer);

/*
** checks the buffer linked list for actions which 
** might have to be executed
*/

void            check_input(t_buf *buffer)
{
    t_buf *tmp;
     // the action keys for the line
    // editing such as the arrow keys

    tmp = NULL;
    if (!buffer)
        fatal("Error in (check_input)");
    tmp = buffer;
    while (tmp)
    {

        if (ft_strcmp(tmp->key, K_LEFT) == 0) 
        {
            ft_putendl("Testing");
            exit(-1); // TESTING
        }

        // have an array of values which require execution
        // each value is correlated to a function pointer
        // return this function pointer and execute

        
        /*
        ** if (buf[0] == 27 && buf[1] == 91 && buf[2] == 68 && buf[3] == 0)
        **     cursor_left(shell);
        ** if (buf[0] == 27 && buf[1] == 91 && buf[2] == 67 && buf[3] == 0)
        **     cursor_right(shell);
        */



        tmp = tmp->next;
    }
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
    t_buf       *buffer;

    buffer = NULL;
    ft_putstr("tamshell$> "); // prompt

    tputs(tgetstr("vs", NULL), 0, putintc);

    // if the buffer equals
    // to enter which is 10
    while (buf[0] != 10)
    {
        ft_bzero(buf, KEY_BUF_SIZE + 1);
        read(STDIN_FILENO, buf, KEY_BUF_SIZE);
        ft_add_buf(&buffer, buf);
        
        check_input(buffer); // WIP

       
   








    //`ce'
        //String of commands to clear from the cursor to the end of the current line.
    //`dl'
        //String to delete the line the cursor is on.
    //`LE'
        // String to move cursor left n columns.
    //`nd'
        //String to move the cursor right one column.



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
