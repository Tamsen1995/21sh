#include "../../../includes/ft_sh.h"


/*
** frees the cursor index linked list
*/

void            free_cursor(t_cursor *cur)
{
    t_cursor *tmp;

    tmp = NULL;
    if (!cur)
        fatal("Error (free_cursor)");
    tmp = cur;
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

void            free_buffer(t_buf *buffer)
{
    t_buf *tmp;

    tmp = NULL;
    if (!buffer)
        return ;
    tmp = buffer;
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
    if (!line || !line->sz)
        fatal("Error (free_line_struct)");
    reset_cursor();
    free_buffer(line->buffer);
    free_cursor(line->cursor);
    if (line->sz)
        free(line->sz);
    ft_putendl("");
}