#include "../../../../includes/ft_sh.h"

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
    t_buf       *ret;
    t_cursor    *tmp_cur;

    ret = NULL;
    tmp_cur = NULL;
    if (!line || !line->first_c || !line->current_c)
        fatal("Error (get_cur_buffer)");
    ret = line->buffer;
    tmp_cur = line->first_c;


    while (ret->next && tmp_cur && tmp_cur->c_ind != line->current_c->c_ind)
    {
        ret = ret->next;
        tmp_cur = tmp_cur->next;
    }
    return (ret); // TODO test result
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
}

/*
** deletes the element before the current cursor position in the buffer
*/

void           del_buf_elem(t_line *line)
{
    t_buf *del;

    del = NULL;
    if (!line || !line->buffer || !line->cursor)
        fatal("Error (del_buf_elem)");
    // getting the buffer element that the cursor
    // is pointing
    del = get_cur_buffer(line);
    if (!del->prev)
        return ;
    // going to the one before since that is the one to be deleted
    if (del->next)
        del = del->prev;
    
    // del is now the element to be deleted
    

    
    printf("\n\n%s\n\n", del->key); // TESTING
    print_list_test(line->buffer); // TESTING

    exit(-1); // TESTING

// TODO fix this function (make it work!)

}

// TODO insert function
//void        insert_at_cursor();

//////////////////////////////////////////////////////////////////////////////////// INSERT / DELETE in relation to current cursor position
