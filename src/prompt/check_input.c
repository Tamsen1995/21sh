#include "../../includes/ft_sh.h"

/*
** checks the buffer linked list for actions which 
** might have to be executed
*/

void            check_input(t_line *line, char *buf)
{
    if (!line)
        fatal("Error (check_input)");
    if (!buf)
        return ;
    cursor_movement(buf, line);
    if (ft_strcmp(buf, K_UP) == 0)
        check_hist(line);
    if (ft_strcmp(buf, K_DOWN) == 0)
        check_hist_down(line);
    if (ft_strcmp(buf, K_BACKSPACE) == 0)
        line->buffer = del_buf_elem(line);
}
