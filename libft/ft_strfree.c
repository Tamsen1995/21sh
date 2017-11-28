#include "../includes/libft.h"

/*
** Takes in a string and then frees it
** points it to NULL after
** if the string is NULL it does nothing
*/

void        ft_strfree(char *string)
{
    if (!string)
        return ;
    free(string);
    string = NULL;
}