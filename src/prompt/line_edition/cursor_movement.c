#include "../../includes/ft_sh.h"

// tputs(tgetstr("le", NULL), 0, putintc); // moves the cursor to the left
void        move_left() // WIP
{

    
}

/*
** Takes care of potential cursor movement
*/
void          cursor_movement(char *key, t_buf *buffer) // WIP
{
    if (ft_strcmp(key, K_LEFT) == 0)
        move_left(buffer);
        
}


