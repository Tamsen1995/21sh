#include "../../../includes/ft_sh.h"

/*
** everytime an arrow key is pressed
** the history list is checked backwards
** changing the buffer within the line structure
*/

void        check_hist(t_line *line)
{
    t_hist *tmp_his;

    tmp_his = NULL;
    if (!line || line->his_index < 0)
        fatal("Error (check_hist)");    
    if (line->his_index == 1 || !line->history)
        return ;
    else if (line->his_index == 0)
        line->his_index = get_last_index(line->history);
    else
        line->his_index--;
    tmp_his = line->history;
    while (tmp_his && tmp_his->index != line->his_index)
        tmp_his = tmp_his->next;
    free_buffer(line->buffer);
    line->buffer = replace_buffer(tmp_his->cmd);
    set_cursor_internal(line);
}

// have an index for every hist list element
// keep track of the current history element index
// if there is none (no index) in the up function, then make the last one the current index
// everytime you enter a history function, either add or subtract index.
// once the appropiate index has been determined in the function, iterate to that list element
// and then replace the buffer with that list element.

// the indexes of the list will start at 1, since 0 will be a placeholder for indicating that there is no current list element selected.