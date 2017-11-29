#include "../../includes/ft_sh.h"

/*
** receives a directory path
** and checks the directory for
** sought after filename
*/

T_BOOL        check_directory(char *dir_path, char *file)
{
    DIR             *dir;
    struct dirent   *ent;
    //char *bin;

    dir = NULL;
    ent = NULL;
    if (!(dir = opendir(dir_path)))
        fatal("Could not open directory in (check_directory)");
    if (!dir_path || !file)
        fatal("Error in (check_directory)"); // remove later
    while ((ent = readdir(dir)))
    { 
        // iterate over all binaries in folder to look for sought after binary
        if (ft_strcmp(ent->d_name, file) == 0)
        {
            closedir(dir);
            return (TRUE);
        }
    }
    closedir(dir);
    return (FALSE);
}
