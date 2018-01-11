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

			// TODO : figure out how to free the tokens list
			// after the next pointer of the previous tokens list has been isolated
	if (ft_find_operator(tokens_tmp) != 0)
	{
		tokens_tmp->prev->next = NULL;
		// setting the next pointer of the previous one to NULL
		// in order to isolate the list

		node->elem = ft_strdup(tokens_tmp->token);
		// the operator as the current node element

		node->left = make_ast(tokens);
		// split the operation
		// with a the lesser priority string on the left

		// TODO : implement the handling of the heredoc handling

		node->right = make_ast(tokens_tmp->next);
		// and the rest of the split up string as the right node
			// call this into the recursion



		// ft_putendl("call recursion");



	}
	else
	{
		ft_putendl("declare node and simply exit condition");
		// simply equate this to the current node
	}
	return (node);
}
