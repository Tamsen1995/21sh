#include "../../includes/ft_sh.h"

// determines whether the given
// string is a redirection or not
int is_redirection(char *s)
{
	char *ret;

	if (s && ((ret = ft_strchr(s, R_OUTPUT)) ||
			  (ret = ft_strchr(s, R_OUTPUT_APPEND)) ||
			  (ret = ft_strchr(s, R_DUP_OUTPUT)) ||
			  (ret = ft_strchr(s, R_INPUT)) ||
			  (ret = ft_strchr(s, R_HERE_DOC)) ||
			  (ret = ft_strchr(s, R_DUP_INPUT)) ||
			  (ret = ft_strchr(s, R_PIPELINE))))
		return (*ret);
	return (FALSE);
}
