#include "../../includes/ft_sh.h"

void				parser(t_shell *shell)
{
    char    	**cmd_line;
    t_tokens 	*tokens;
	t_ast_node	*tree;

    cmd_line = NULL;
    tokens = NULL;
	tree = NULL;
    if (!shell || !shell->cmds->args)
        fatal("Error in : (parser)");
    cmd_line = shell->cmds->args;
    tokens = lexer(cmd_line);
	tree = make_ast(tokens);

    exit (-1); // TESTING
}