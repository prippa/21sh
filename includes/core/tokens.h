#ifndef TOKENS_H
# define TOKENS_H

# include "syntax_characters.h"

# define TOKEN_SIZE 5

static const char	g_tokens[TOKEN_SIZE] =
{
	SEMICOLON_C,
	PIPE_C,
	REDIRECT_IN_C,
	REDIRECT_OUT_C,
	FDA_C
};

#endif
