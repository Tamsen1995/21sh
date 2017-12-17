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
#include <fcntl.h>
#include <stdio.h>
#include "../includes/libft.h"
#include "../includes/ft_ls.h"


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
}					t_buf;

/*
** struct responsible for the line edition
** in the prompt
*/

typedef struct			s_line
{	
	struct s_buf		*buffer;
	struct s_cursor		*cursor;
	struct winsize		*sz;
	char				*prompt;
	int					prompt_len;
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
** 21sh starting here
*/

t_cmds      		*store_commands(char *commands);
int             	putintc(int c);
void				print_buffer(t_buf *buffer);
void         		cursor_movement(char *key, t_line *line); // WIP
T_BOOL        		term_action(char *buf);

/*
** line buffer/edition functions:
*/

void				ft_add_buf(t_buf **begin_list, char *key);
char     		   	*stringify_buffer(t_buf  *buffer);
int					list_len(t_buf *buffer);

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