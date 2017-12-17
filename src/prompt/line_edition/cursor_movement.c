#include "../../../includes/ft_sh.h"

// tputs(tgetstr("le", NULL), 0, putintc); // moves the cursor to the left
void        move_left() // WIP
{
    tputs(tgetstr("le", NULL), 0, putintc);
}

/*
** Takes care of potential cursor movement
*/

void          cursor_movement(char *key, t_buf *buffer) // WIP
{
    if (!key || !buffer)
        return ;

    if (ft_strcmp(key, K_LEFT) == 0)
        move_left();
    // if (ft_strcmp(key, K_RIGHT) == 0)
        // move_right(buffer);
    
        
}


