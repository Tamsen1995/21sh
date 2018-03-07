#ifndef REDIRECTIONS_H
# define REDIRECTIONS_H

#include <unistd.h>

/*
** enum
*/

enum					e_replacement
{
	S_WORD = -42,
	S_LINE = -41,
	R_OUTPUT = -40,
	R_OUTPUT_APPEND = -39,
	R_INPUT = -38,
	R_PIPELINE = -37,
	R_HERE_DOC = -36,
	R_DUP_INPUT = -35,
	R_DUP_OUTPUT = -34
};

#endif