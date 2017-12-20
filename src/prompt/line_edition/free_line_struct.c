#include "../../../includes/ft_sh.h"


/*
** frees the cursor index linked list
*/

void            free_cursor(t_line *line)
{
    t_cursor *tmp;

    tmp = NULL;
    if (!line || !line->cursor)
        fatal("Error (free_cursor)");
    tmp = line->cursor;
    while (tmp->next)
        tmp = tmp->next;
    while (tmp->prev)
    {
        tmp = tmp->prev;
        free(tmp->next);
    }
    free(tmp);
}

/*
** freeing the line buffer
*/

void            free_line_buf(t_line *line)
{
    t_buf *tmp;

    tmp = NULL;
    if (!line || !line->buffer)
        fatal("Error (free_line_buf)");
    tmp = line->buffer;
    while (tmp->next)
        tmp = tmp->next;
    while (tmp->prev)
    {
        tmp = tmp->prev;
        ft_strfree(tmp->next->key);
        free(tmp->next);
    }
    ft_strfree(tmp->key);
    free(tmp);
}

/*
** function which frees the line edition
** structure
*/


void            free_line_struct(t_line *line)
{
    if (!line)
        fatal("Error (free_line_struct)");
    free_line_buf(line);
    free_cursor(line);
    if (line->sz)
        free(line->sz);
    
    // TODO finish function
}
