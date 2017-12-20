#include "../../../includes/ft_sh.h"

/*
** freeing the line buffer
*/

void            free_line_buf(t_line *line)
{
    t_buf *tmp;

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
    free_line_buf(line); // WIP
  //  free_cursor(line); // WIP
    //free_win_sz();
    
    // TODO finish function
}
