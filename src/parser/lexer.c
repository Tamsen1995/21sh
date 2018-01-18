#include "../../includes/ft_sh.h"

/*
** assigns token types for the lexer
*/

enum e_tokentype	tok_type(char *potential_token)
{
    if (!potential_token)
        fatal("Error in : tok_type");
    if (ft_strcmp(potential_token, "|") == 0)
        return (PIPE);
    else if (ft_strcmp(potential_token, "<") == 0)
        return (INPUT_RE);
    else if (ft_strcmp(potential_token, ">") == 0)
        return (OUTPUT_RE);
    else if (ft_strcmp(potential_token, "2>") == 0)
        return (ERR_RE);
    else if (ft_strcmp(potential_token, "\0") == 0)
        return (CHAR_NULL);
    return (CHAR_GENERAL);
}

/*
** allocates a new token list element
*/

t_tokens      *ft_new_tok(char *token)
{
    t_tokens *new;

    if (!(new = (t_tokens *)malloc(sizeof(t_tokens))))
        fatal("Error: could not allocate env var list elem in ft_new_env");
    new->next = NULL;
    new->token = NULL;
    new->tok_type = tok_type(token);
    new->token = ft_strdup(token);
    new->tok_ind = 0;
    return (new);
}

void		ft_add_token(t_tokens **begin_list, char *token)
{
    t_tokens *tmp;

    tmp = NULL;
	if (!*begin_list)
	{
		*begin_list = ft_new_tok(token);
		return ;
	}
    else
    {
        tmp = *begin_list;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = ft_new_tok(token);
        tmp->next->prev = tmp;
    }
}


/*
** (re-) declares the index count for the token list
*/

void         init_token_index(t_tokens *tokens)
{
    int      i;
    t_tokens *tmp;

    i = 0;
    tmp = NULL;
    if (!tokens)
        fatal("Error in : (init_token_index)");
    tmp = tokens;
    while (tmp)
    {
        tmp->tok_ind = i;
        i++;
        tmp = tmp->next;
    }

}

t_tokens     *lexer(char **cmd_line)
{
    int         i;
    t_tokens     *tokens;

    i = 0;
    tokens = NULL;
    if (!cmd_line)
        fatal("Error in : (lexer)");
    while (cmd_line[i])
    {
        ft_add_token(&tokens, cmd_line[i]);
        i++;
    }
    init_token_index(tokens);
    return (tokens);
}
