#include "../../../includes/ft_sh.h"

// tputs(tgetstr("le", NULL), 0, putintc); // moves the cursor to the left
void        move_left(t_buf *buffer) // WIP
{
    t_buf *tmp;

    tmp = NULL;
    if (!buffer)
        fatal("Error in (move_left)");
    tmp = buffer;
    if (tmp->cursor == TRUE)
        return ;
    while (tmp->next && tmp->next->cursor == FALSE)
        tmp = tmp->next;
    if (!tmp->next)
        fatal("Error2 in (move_left)");
    tmp->next->cursor = FALSE;
    tmp->cursor = TRUE;
    tputs(tgetstr("le", NULL), 0, putintc);
}

/*
** Takes care of potential cursor movement
*/

void          cursor_movement(char *key, t_buf *buffer) // WIP
{
    if (ft_strcmp(key, K_LEFT) == 0)
        move_left(buffer);
    // if (ft_strcmp(key, K_RIGHT) == 0)
        // move_right(buffer);
    
        
}


