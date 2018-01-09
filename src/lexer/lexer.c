#include "../../includes/ft_sh.h"

enum e_redir	redir_type(char *redir, char *file)
{
	if (!redir || !file)
		fatal("Error (redir_type)");
	if (ft_strcmp(redir , "<") == 0 && access(file, W_OK) == 0)
		return (INPUT_RE);
	if (ft_strcmp(redir , ">") == 0 && access(file, W_OK) == 0)
		return (OUTPUT_RE);
	if (ft_strcmp(redir , "2>") == 0 && access(file, W_OK) == 0)
		return (ERR_RE);
	return (NO_REDIRECTION);
}
