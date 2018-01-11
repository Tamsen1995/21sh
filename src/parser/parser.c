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


/*
** finds an operator in
** a list of tokens
*/

int					ft_find_operator(t_tokens *tokens) // WIP
{
	t_tokens *tmp;

	tmp = NULL;
	if (!tokens)
		fatal("Error in : ft_find_operator");

	while (tmp)
	{
		//  returns a non zero value upon finding 
		// an operator

		tmp = tmp->next;
	}

	return (0);
}


t_ast_node			*make_ast(t_tokens *tokens) // WIP
{
	t_ast_node	*node;
	t_tokens *tokens_tmp;

	node = NULL;
	tokens_tmp = NULL;
	node  = ft_create_node();
	if (!tokens)
		fatal("Error in : (make_tree)");
	tokens_tmp = tokens;
	if (ft_find_operator(tokens_tmp) != 0)
	{
		tokens_tmp->prev->next = NULL;
		node->left = make_ast(tokens_tmp->prev);
		node->elem = ft_strdup(tokens_tmp->token);
		node->right = make_ast(tokens_tmp->next);


		// TODO : figure out how to free the tokens

		// split the operation
		// with a operand on the left
		ft_putendl("call recursion");



		// the operator as the current node element
		// and the rest of the split up string as the right node
			// call this into the recursion
	}
	else
	{
		ft_putendl("declare node and simply exit condition");
		// simply equate this to the current node
	}
	return (node);
}


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