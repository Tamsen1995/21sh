#ifndef FT_SH_H
# define FT_SH_H

#include <termcap.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/param.h>
#include <signal.h>
#include <stdarg.h>
#include <fcntl.h>
#include <stdio.h>
#include "../includes/libft.h"
#include "../includes/ft_ls.h"

# define K_RETURN		"\xa\x0\x0\x0\x0\x0"
# define K_BACKSPACE	"\x7f\x0\x0\x0\x0\x0"
# define K_UP			"\x1b\x5b\x41\x0\x0\x0"
# define K_DOWN			"\x1b\x5b\x42\x0\x0\x0"
# define K_RIGHT		"\x1b\x5b\x43\x0\x0\x0"
# define K_LEFT			"\x1b\x5b\x44\x0\x0\x0"
# define MAX_BUF_SIZE 2048
# define BUFF_SIZE 8
# define BIN "/bin/"
# define T_BOOL int
# define KEY_BUF_SIZE	6
# define TRUE 1
# define FALSE 0



/*	
struct winsize
{
  unsigned short ws_row;	// rows, in characters 
  unsigned short ws_col;	// columns, in characters 
  unsigned short ws_xpixel;	// horizontal size, pixels 
  unsigned short ws_ypixel;	// vertical size, pixels 
};
*/


/*
** cursor linked list
** every element represents a potential cursor position
*/

typedef struct			s_cursor
{
	struct s_cursor		*next;
	struct s_cursor		*prev;
	int					c_ind; // cursor index
	T_BOOL				cursor;
}						t_cursor;

/*
** this list will serve as a buffer for
** potential commands
** each character represents a keystroke 
** made into the terminal
*/ 

typedef struct		s_buf
{
	struct s_buf	*next;
	struct s_buf	*prev;
	char 			*key;
	int				ind; // The index of the buffer
}					t_buf;

/*
** struct responsible for the line edition
** in the prompt
*/

typedef struct			s_line
{	
	struct s_buf		*buffer;
	struct s_cursor		*cursor;
	struct s_cursor		*first_c; // the cursor cannot go past this ever because this is where the prompt starts
	struct s_cursor		*last_c; // last possible cursor position
	struct s_cursor		*current_c;
	struct winsize		*sz;
	char				*prompt;
}						t_line;

/*
** a  linked list of commands here
** each command is a 2d array
** storing the command itself as well as its
** parameters
*/ 

typedef struct		s_cmds
{
	struct s_cmds	*next;
	struct s_cmds	*prev;
	char 			**args;
}					t_cmds;

/*
** This list indicates the env variables of the shell
*/

typedef struct		s_env
{
	struct s_env	*next;
	struct s_env	*prev;
	char			*name;
	char			*value;
}					t_env;

typedef struct		s_shell
{
	int					argc; // Amount of arguments passed into my shell (for each individual command)
	struct s_cmds		*cmds; // a list of commands
	struct s_env		*env; // The environment variables
	char				*path_var; // The value of PATH
	char				*bin_dir; // the binary folder in which the sought after CURRENT command is
	struct winsize		*sz;
	struct termios		*termold;
	struct termios		*term;

}					t_shell;



/*
** Testing functions
*/

void           print_list_test(t_buf *buffer);

/*
** Testing functions
*/


/*
** 21sh starting here
*/

t_cmds      		*store_commands(char *commands);
int             	putintc(int c);
void				print_buffer(t_line *line);
void         		cursor_movement(char *key, t_line *line);
t_cursor    	   	*init_cursor(int win_size);
T_BOOL        		term_action(char *buf);
t_cursor			*get_first_c(t_line *line);

/*
** line buffer/edition functions:
*/

void				ft_add_buf(t_buf **begin_list, char *key);
char     		   	*stringify_buffer(t_buf  *buffer);
int					list_len(t_buf *buffer);
void				free_line_struct(t_line *line); // Freeing the struct
t_buf          		*del_buf_elem(t_line *line);
void  		        init_buf_ind(t_buf	*buffer);
void     	       	free_buffer(t_buf *buffer);
void  			    reset_cursor();
void      		    check_input(t_line *line, char *buf);
void 		       	prompt_cursor(t_line *line);
void  				insert_buffer(t_line *line, char *key);
t_buf  			    *ft_new_buf(char *key);



/*
** 21sh ending here
*/

T_BOOL				check_builtin_path(t_shell *shell);
int					exec_builtin(t_shell *shell);
T_BOOL				check_builtins(char *cmd);
void				change_env_var(char **args, t_shell *shell);
T_BOOL				check_bin_path(t_shell *shell);
T_BOOL    		    check_directory(char *dir_path, char *file);
void				get_path_var(t_shell *shell);
void    		    free_shell(t_shell *shell);
int					sh_unsetenv(char **args, t_shell *shell);
void				ft_putenv(t_env **begin_list, char *name, char *value);
T_BOOL  		    check_bin_cmd(t_shell *shell);
int      			sh_env(t_shell *shell);
int   				sh_setenv(char **args, t_shell *shell);
t_env   		    *init_env(char **envv);
int					get_next_line(int const fd, char **line);
int					sh_execute(char **envv, t_shell *shell);
int					sh_launch(char **envv, t_shell *shell);
int					sh_cd(char **args, t_shell *shell);
int					sh_exit(void);
int					sh_echo(char **args);
t_shell				*init_shell(int ac, char **av, char **envv);
char				*prompt_loop(void);

#endif