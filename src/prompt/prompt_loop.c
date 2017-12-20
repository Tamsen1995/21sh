#include "../../includes/ft_sh.h"


//////////////////////////////////////////////////////////////////////////////////// INSERT / DELETE in relation to current cursor position


// find the buffer element at which the cursor is currently positioned at
    // go to the current_c from first_c
        // count the number of jumps/iterations in the process
    // jump / iterate said number of times in the buffer
        // boom ! you've got the desired buffer position into which you can insert/delete


/*
** returns a pointer to the 
** buffer element which is found at
** the current tracked cursor position
*/

t_buf       *get_cur_buffer(t_line *line)
{
    int         i;
    int         k;
    t_buf       *ret;
    t_cursor    *tmp_cur;

    i = 0;
    k = 0;
    ret = NULL;
    tmp_cur = NULL;
    if (!line || !line->first_c || !line->current_c)
        fatal("Error (get_cur_buffer)");
    ret = line->buffer;
    tmp_cur = line->first_c;
    while (tmp_cur && tmp_cur->c_ind != line->current_c->c_ind)
    {
        k++;
        tmp_cur = tmp_cur->next;
    }
    while (ret &&  i < k)
    {
        i++;
        ret = ret->next;
    }
    return (ret); // TODO test result
}





    /*
       // When not first node, follow the normal deletion process
 
    // find the previous node
    struct Node *prev = head;
    while(prev->next != NULL && prev->next != n)
        prev = prev->next;
 
    // Check if node really exists in Linked List
    if(prev->next == NULL)
    {
        printf("\n Given node is not present in Linked List");
        return;
    }
 
    // Remove node from Linked List
    prev->next = prev->next->next;
 
    // Free memory
    free(n);
 
    return; 
}
    */



/*
** deletes the element before the current cursor position in the buffer
*/

void           del_buf_elem(t_line *line)
{
    t_buf *del_elem; // buffer element at which the buffer is positioned

    
    t_buf *prev;

    del_elem = NULL;
    prev = NULL;
    if (!line)
        fatal ("Error (del_buf_elem)");
    del_elem = get_cur_buffer(line);
    if (del_elem->ind == line->buffer->ind)
        return ; // if it is the first element
    prev = line->buffer; // putting previous to the head of the list
    del_elem = del_elem->prev;
    while (prev->next != NULL && prev->next->ind != del_elem->ind)
        prev = prev->next;
    if (!prev->next)
        fatal("No such elem in (del_buf_elem)");
    prev->next = prev->next->next;
    ft_strfree(del_elem->key);
    free(del_elem);

    line->last_c = line->last_c->prev;
    line->current_c = line->current_c->prev;

    tputs(tgetstr("le", NULL), 0, putintc);




// TODO fix this function (make it work!)



}

// TODO insert function
//void        insert_at_cursor();

//////////////////////////////////////////////////////////////////////////////////// INSERT / DELETE in relation to current cursor position



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

    if (ft_strcmp(buf, K_BACKSPACE) == 0)
        del_buf_elem(line);

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
        check_input(line, buf); // WIP // edit the buffer according to action requested
        if (term_action(buf) == FALSE) // WIP
        {
            ft_add_buf(&line->buffer, buf, buf_ind); // I might have to heavily modify this in order for it to insert the desired keys at the current_c position
            // everytime a new key is added to the buf, 
            // the last possible cursor position shall move as well


            print_buffer(line->buffer);
            line->current_c = line->current_c->next;
            line->last_c = line->last_c->next;
            buf_ind++;
        }
    }
    cmd_line = stringify_buffer(line->buffer);
    free_line_struct(line);
    return (cmd_line);
}
