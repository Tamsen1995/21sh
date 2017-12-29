#include "../../../includes/ft_sh.h"

/*
** determines if the inputted buffer
** represents an action
*/

T_BOOL          term_action(char *buf)
{
    if (!buf)
        return (FALSE);
    if (ft_strcmp(buf, K_RETURN) == 0)
        return (TRUE);
    if (ft_strcmp(buf, K_LEFT) == 0)
        return (TRUE);
    if (ft_strcmp(buf, K_RIGHT) == 0)
        return (TRUE);    
    if (ft_strcmp(buf, K_UP) == 0)
        return (TRUE);
    if (ft_strcmp(buf, K_BACKSPACE) == 0)
        return (TRUE);
    return (FALSE);
}