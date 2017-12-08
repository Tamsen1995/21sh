#include "../includes/ft_sh.h"


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
        tmp->next = ft_new_buf(key);
        tmp->next->prev = tmp;
    }
}


// TESTING purposes
void        print_list(t_buf *buffer)
{
    t_buf *tmp;

    tmp = buffer;
    while (tmp)
    {
        ft_putstr(tmp->key);
        tmp = tmp->next;
    }

}

/*
** This routine will read the characters of the line buffer
** check them into a linked list
** make sure of the cursor position (check for its position and modify it)
** insert text at the appropiate line
** attune the terminal in a way which will make reading all the characters possible

** Display the initial contents of the text buffer on the screen.
** Get a keystroke from the user.
** If the keystroke is a command (like delete or backspace), dispatch or carry out that command.
** If the keystroke is a character, insert it into the text buffer (or replace the current character if not in insert mode).
** Display the updated contents of the text buffer on the screen.
*/

void        prompt_loop(void)
{

	char		buf[KEY_BUF_SIZE + 1];
    t_buf       *buffer; // The list of the strings, to be the potential commands

    buffer = NULL;
    ft_putstr("tamshell$> "); // prompt
    while (buf[0] != 10)
    {
        // ft_putendl(""); // prompt

        ft_bzero(buf, KEY_BUF_SIZE + 1);
        read(STDIN_FILENO, buf, KEY_BUF_SIZE);

        ft_add_buf(&buffer, buf);



        //TODO for every new buffer input, make a new list element

        // get_next_line(STDIN_FILENO, &buf);
        // ft_putstr(buf);
    }
    print_list(buffer); // TESTING

    exit(-1); // TESTING

    // get_next_line(0, &buf);
    // somewhere here I need to check for input
    // to see if there is an arrow key  I need to be able
    // to read. This will constitute for the cursor movement


    // if ()
      //  print_selected(shell);

//    return (buf);
}