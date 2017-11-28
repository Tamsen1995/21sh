#include "../includes/libft.h"

// I think this should work
void        free_twod_arr(char **arr)
{
    int i;

    if (!arr)
       return ;
    i = 0;
    while (arr[i])
    {
        free(arr[i]);
        arr[i] = NULL;
        i++;
    }
    free(arr);
    arr = NULL;
}