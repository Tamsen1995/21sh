#include "../../../includes/ft_sh.h"

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
    while (ret->next &&  i < k)
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
    del_elem = NULL;

    line->last_c = line->last_c->prev;
    line->current_c = line->current_c->prev;

    //tputs(tgetstr("le", NULL), 0, putintc);


// TODO fix this function (make it work!)

}

// TODO insert function
//void        insert_at_cursor();

//////////////////////////////////////////////////////////////////////////////////// INSERT / DELETE in relation to current cursor position
