#ifndef FT_LS_H
# define FT_LS_H
# define BUF_SIZE 1024

# include				"../includes/libft.h"
# include				<dirent.h>
# include				<unistd.h>
# include				<pwd.h>
# include				<grp.h>
# include				<time.h>
# include				<sys/stat.h>
# include				<sys/types.h>
# include				<errno.h>


void                free_list_elem(t_stack *tmp);
char		    	*make_dir_path(char *dir_path);
char 		        **sort_args(char **av_tmp);
char	        	**check_args_for_dirs(char **av_tmp, int i, int ac);
t_bool	        	is_valid_folder(char *path);
char 	            **copy_args(int ac, char **av);
t_stack				*extr_sought_fl(t_stack *fls, char *fl_path);
t_stack				*handle_single_fl(char *fl_path, char *flags);
void				free_list(t_stack *list);
void                print_total_blocks(t_stack *file, char *flags);
t_bool		        is_hidden_file(t_stack *file);
void        		print_flags(t_stack *file, char *flags);
void		        print_dir(t_stack *files, char *flags);
void                output_module(t_stack *files, char *flags);
char                *extract_nbr_of_links(struct stat buf);
char                *extract_file_size(struct stat buf);
char                *isolate_date_time(char *temps);
void                extract_date_time(struct stat buf, t_fields *fields);
char                *extract_group(struct stat buf);
char                *extract_owner(struct stat buf);
void                extract_permissions_mode(struct stat fileStat, t_stack *file);
t_fields            *alloc_fields(void);
t_fields			*get_file_info(t_stack *file);
void        		error_msg(char *message);
void	    		print_dir_path(t_stack *file, char *flags);
char				*make_path_dir(char *name, char *cathis);
t_stack     		*register_fls_in_dir(char *name, char *flags);
t_bool				not_curr_and_prev(t_stack *entry);
void   				out_entire_stack(t_stack *stack, char *flags);
int		    		parse_flags(int ac, char **av, char *flags);
t_stack				*alloc_list(char *name,char *flags);
t_flags				*get_flags(int argc, char **argv);
char				*make_path_dir(char *name, char *cathis);
int					ft_init_flags(t_flags **flags);
void				det_flags(char *flag, t_flags **flags);
void				big_r(DIR *rep);


#endif