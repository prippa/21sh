#include "line_syntax.h"
#include "syntax_characters.h"

#define UN_TOKENS_SIZE 8
#define UN_TOKENS_SIZE_PIPE 3

static const char	*g_ut[UN_TOKENS_SIZE] =
{
	(char[3]){SEMICOLON_C, SEMICOLON_C, 0},
	(char[2]){SEMICOLON_C, 0},
	(char[3]){REDIRECT_IN_C, REDIRECT_IN_C, 0},
	(char[2]){REDIRECT_IN_C, 0},
	(char[3]){REDIRECT_OUT_C, REDIRECT_OUT_C, 0},
	(char[2]){REDIRECT_OUT_C, 0},
	(char[2]){PIPE_C, 0},
	(char[2]){FDA_C, 0},
};

static const char	*g_ut_pipe[UN_TOKENS_SIZE_PIPE] =
{
	(char[2]){SEMICOLON_C, 0},
	(char[2]){PIPE_C, 0},
	(char[2]){FDA_C, 0},
};

static t_bool	ls_check_tokens(const char *line)
{
	uint8_t	i;

	i = -1;
	while (++i < UN_TOKENS_SIZE)
		if (ft_strnequ(line, g_ut[i], ft_strlen(g_ut[i])))
		{
			rl_ls_syntax_err_wtf_token(g_ut[i]);
			return (true);
		}
	return (false);
}

t_lexer_status	ls_check_word(t_line_syntax *ls, t_line *ln)
{
	while (ln->line[ls->i])
	{
		if (!ft_isspace(ln->line[ls->i]))
		{
			if (ls_check_tokens(&ln->line[ls->i]))
				return (LS_SYNTAX_ERR);
			--ls->i;
			return (LS_OK);
		}
		++ls->i;
	}
	return (LS_NEW_PROMPT);
}

static t_bool	ls_check_tokens_for_pipe(const char *line)
{
	uint8_t	i;

	i = -1;
	while (++i < UN_TOKENS_SIZE_PIPE)
		if (ft_strnequ(line, g_ut_pipe[i], ft_strlen(g_ut_pipe[i])))
		{
			rl_ls_syntax_err_wtf_token(g_ut_pipe[i]);
			return (true);
		}
	return (false);
}

t_lexer_status	ls_check_word_for_pipe(t_line_syntax *ls, t_line *ln)
{
	while (ln->line[ls->i])
	{
		if (!ft_isspace(ln->line[ls->i]))
		{
			if (ls_check_tokens_for_pipe(&ln->line[ls->i]))
				return (LS_SYNTAX_ERR);
			--ls->i;
			return (LS_OK);
		}
		++ls->i;
	}
	return (LS_NEW_PROMPT);
}
