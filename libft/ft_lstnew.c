/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 21:07:58 by tbui              #+#    #+#             */
/*   Updated: 2015/11/25 21:33:51 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char			*make_path_dir(char *name, char *cathis)
{
	char *nw_path;
	size_t l; //length for new path

	l = ft_strlen(name) + ft_strlen(cathis);
	l = l + 2;
	nw_path = NULL;
	if (!(nw_path = (char *)malloc(sizeof(char) * l + 1)))
		error_msg("Memory for a path directory name could not be allocated ! (make_path_dir)");
	nw_path = ft_strcpy(nw_path, name);
	nw_path = ft_strcat(nw_path, "/");
	nw_path = ft_strcat(nw_path, cathis);
	return (nw_path);
}

t_filetype		get_file_type(struct dirent *ent)
{
	if (ent->d_type == DT_REG)
		return (REG);
	if (ent->d_type == DT_BLK)
		return (BLOCK);
	if (ent->d_type == DT_CHR)
		return (CHAR_SP);
	if (ent->d_type == DT_DIR)
		return (DIRECTORY);
	if (ent->d_type == DT_LNK)
		return (SYMLINK);
	if (ent->d_type == DT_SOCK)
		return (SOCK_LINK);
	if (ent->d_type == DT_FIFO)
	{
		ft_putendl("YOUNG AND STUPID");
		return (FIFO);
	}
	return (REG);
}


void system_link_module(t_stack *file, char *flags)
{
	char buf[1024];
	ssize_t link_size;
	ssize_t attr_size;
	char *tmp;

	link_size = 0;
	attr_size = 0;
	link_size = readlink(file->path, buf, sizeof(buf)); // actually getting the system link
	buf[link_size] = '\0'; // null terminating the buffer
	if (flags[f_list])
	{
		tmp = ft_strjoin(file->filename, " -> ");
		free(file->filename);
		file->filename = ft_strjoin(tmp, buf);
		free(tmp);
	}
	//	attr_size = lgetxattr(file->path, buf, value, link_size);
}

// This function takes in an entry in the directory stream and the path of the directory
// itself and then returns a stack elem which contains all its necessary information
t_stack		*ft_lstnew(struct dirent *ent, char *path, char *flags)
{
	t_stack	*alist;
	struct stat fstat;
	char *nw_path;

	if (!(alist = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	// put the file name into the list
	alist->filename = ft_strdup(ent->d_name);	
	alist->path = make_path_dir(path, alist->filename); // concatenating the path into the path pointer in struct	
	alist->type = INVALID;
	alist->type = get_file_type(ent);
	if (alist->type == SYMLINK)
		system_link_module(alist, flags);
	if (lstat(alist->path, &(alist->stats)) < 0)
		error_msg("Was not able to retrieve stat information of file ! (ft_lstnew)");
	alist->next = NULL;
	alist->prev = NULL;
	alist->fields = NULL;
	return (alist);
}
