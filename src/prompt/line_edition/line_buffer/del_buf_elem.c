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


/*
** frees a buf element
*/
void            free_buf_elem(t_buf *buf_elem)
{
    ft_strfree(buf_elem->key); // TESTING
    free(buf_elem);
    buf_elem = NULL;
}

/*
** deletes the element before the current cursor position in the buffer
*/

void           del_buf_elem(t_line **line)
{
    t_buf *del;
    t_buf *tmp;

    del = NULL;
    tmp = NULL;
    if (!(*line) || !(*line)->buffer || !(*line)->cursor)
        fatal("Error (del_buf_elem)");
    // getting the buffer element that the cursor
    // is pointing
    del = get_cur_buffer((*line));
    tmp = (*line)->buffer;
    if (del->ind == (*line)->buffer->ind || !del->prev)
        return ;
    // going to the one before since that is the one to be deleted
    if (del->next)
        del = del->prev;

    // putting the tmp pointer to the position of the item to be deleted
    while (tmp->ind != del->ind)
        tmp = tmp->next;
    
    // if the last element is selected
    if (!del->next)
    {
     //   free_buf_elem(tmp);
     // somehow free the list
        tmp->prev->next = NULL;
        return ;
    }
 
    
    //  ft_putendl(tmp->key); // TESTING

    printf("\n\n%s\n\n", tmp->key); // TESTING
    exit(-1); // TESTING

// TODO fix this function (make it work!)

}

// TODO insert function
//void        insert_at_cursor();

//////////////////////////////////////////////////////////////////////////////////// INSERT / DELETE in relation to current cursor position
