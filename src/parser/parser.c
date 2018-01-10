#include "../../includes/ft_sh.h"


static t_ast_node	*ft_create_node(void)
{
	t_ast_node	*node;

	node = NULL;
	if (!(node = (t_ast_node*)malloc(sizeof(t_ast_node))))
		return (NULL);
	ft_bzero(node, sizeof(t_ast_node));
	node->stdin = 0;
	node->stdout = 1;
	node->stderr = 2;
	node->fd_from = -2;
	node->fd_to = -2;
	node->cmd = NULL;
	return (node);
}


t_ast_node	*make_ast(t_tokens *tokens) // WIP
{
	t_ast_node	*tree;

	tree = NULL;
	tree  = ft_create_node();
	if (!tokens)
		fatal("Error in : (make_tree)");
	return (tree);
}


void        parser(t_shell *shell)
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