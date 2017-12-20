#include "../../../includes/ft_sh.h"

void        move_right() // WIP
{
    tputs(tgetstr("nd", NULL), 0, putintc);
}

void        move_left(t_line *line) // WIP
{
    if (!line || !line->cursor || \
        !line->first_c || !line->current_c)
        fatal("Error (move_left)");
    if (line->current_c->c_ind > line->first_c->c_ind)
    {
        line->current_c = line->current_c->prev;
        tputs(tgetstr("le", NULL), 0, putintc);
    }

}

/*
** Takes care of potential cursor movement
*/

void          cursor_movement(char *key, t_line *line) // WIP
{
    if (!line)
        fatal("Error (cursor_movement)");
    if (!key || !line->buffer)
        return ;
    if (ft_strcmp(key, K_LEFT) == 0)
        move_left(line);
    if (ft_strcmp(key, K_RIGHT) == 0)
        move_right();       
}