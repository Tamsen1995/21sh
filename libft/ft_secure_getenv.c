#include "../includes/libft.h"

/*
** my personal secured getenv
** takes in the env_var's name and returns its value
*/

char            *ft_secure_getenv(const char *name)
{
    char *ret;

    ret = NULL;
    if ((ret = getenv(name)) == NULL)
        fatal("Could not get env_var in (ft_secure_getenv)");
    return (ret);
}
