#include "../../../includes/ft_sh.h"

/*
** replaces the buffer linked list
** with the given string.
** each character is going to be another element
** in the linked list
*/

t_buf        *replace_buffer(char *string)
{
    int         i;
    t_buf       *new_buf;
    char        key[2];

    i = 0;
    new_buf = NULL;
    if (!string)
        fatal("Error (replace_buf)");
    while (string[i])
    {
        ft_bzero(key, 2);
        key[0] = string[i];
        ft_add_buf(&new_buf, key);
        i++;
    }
    return (new_buf);
}
