#ifndef STRUCTS_H
# define STRUCTS_H


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

enum					e_redir
{
	IN,
	OUT,
	ERR,
	NO_REDIR
};

enum					e_tokentype
{
	ND_OR,
	PIPE,
	INPUT_RE,
	OUTPUT_RE,
	ERR_RE,
	TXT_CMD,
    CHAR_NULL,
    CHAR_GENERAL
};


/*
** history of the commands
** given in the past for the arrow up keys
*/

typedef struct		s_hist
{
	struct s_hist	*next;
	struct s_hist	*prev;
	int				index;
	char			*cmd;
	T_BOOL			current;
}					t_hist;


/*
** cursor linked list
** every element represents a potential cursor position
*/

typedef struct			s_cursor
{
	struct s_cursor		*next;
	struct s_cursor		*prev;
	int					c_ind;
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
	int				ind;
}					t_buf;

/*
** struct responsible for the line edition
** in the prompt
*/

typedef struct			s_line
{	
	int					his_index;
	struct s_hist		*history;
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
	struct s_fds		*in_fds;
	struct s_fds		*out_fds;
	struct s_fds		*err_fds;
	struct s_cmds		*next;
	struct s_cmds		*prev;
	char 				**args;


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
	struct s_hist		*history;
	int					argc; // Amount of arguments passed into my shell (for each individual command)
	struct s_cmds		*cmds; // a list of commands

	// TODO : ASTroot

	struct s_env		*env; // The environment variables
	char				*path_var; // The value of PATH
	char				*bin_dir; // the binary folder in which the sought after CURRENT command is
	struct winsize		*sz;
	struct termios		*termold;
	struct termios		*term;

}					t_shell;

typedef struct		s_fds
{
	struct s_fds		*next;
    int                 fd;
}					t_fds;

typedef struct			s_tokens
{
	struct s_tokens		*next;
	enum e_tokentype	tok_type;
	char				*token;
}						t_tokens;

typedef struct			s_ast_node
{
	char			*elem;
	int				type;
	int				stdin;
	int				stdout;
	int				stderr;
	int				fd_from;
	int				fd_to;
	char			**cmd;
	struct s_node	*left;
	struct s_node	*right;
}						t_ast_node;



#endif