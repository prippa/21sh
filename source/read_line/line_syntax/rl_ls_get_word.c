#include "line_syntax.h"
#include "tokens.h"

static t_bool is_token(char c)
{
	uint8_t	i;

	i = -1;
	while (++i < TOKEN_SIZE)
		if (c == g_tokens[i])
			return (true);
	return (false);
}

static void	ls_gw_sq_valid(t_line_syntax *ls, t_line *ln,
				char **word, size_t *word_size)
{
	char	*start;
	size_t	len;

	start = &ln->line[++ls->i];
	len = 0;
	while (ln->line[ls->i])
	{
		if (ln->line[ls->i] == SINGLE_QUOTES_C)
			break ;
		++len;
		++ls->i;
	}
	if (len)
	{
		ft_strjoin_free(word, start, *word_size, len);
		*word_size += len;
	}
}

static void	ls_gw_bs_valid(t_line_syntax *ls, t_line *ln,
				char **word, size_t *word_size)
{
	ft_strjoin_free(word, &ln->line[++ls->i], *word_size, 1);
	*word_size += 1;
}

static void	ls_gw_dq_valid(t_line_syntax *ls, t_line *ln,
				char **word, size_t *word_size)
{
	++ls->i;
	while (ln->line[ls->i])
	{
		if (ln->line[ls->i] == DOUBLE_QUOTES_C)
			break ;
		if (ln->line[ls->i] == BACKSLASH_C)
			ls_gw_bs_valid(ls, ln, word, word_size);
		else
		{
			ft_strjoin_free(word, &ln->line[ls->i], *word_size, 1);
			*word_size += 1;
		}
		++ls->i;
	}
}

char		*ls_get_word(t_line_syntax *ls, t_line *ln)
{
	char	*word;
	size_t	word_size;

	word = ft_strdup(EMPTY_STR);
	word_size = 0;
	while (ln->line[ls->i])
	{
		if (is_token(ln->line[ls->i]) || ft_isspace(ln->line[ls->i]))
			break ;
		if (ln->line[ls->i] == SINGLE_QUOTES_C)
			ls_gw_sq_valid(ls, ln, &word, &word_size);
		else if (ln->line[ls->i] == DOUBLE_QUOTES_C)
			ls_gw_dq_valid(ls, ln, &word, &word_size);
		else if (ln->line[ls->i] == BACKSLASH_C)
			ls_gw_bs_valid(ls, ln, &word, &word_size);
		else
		{
			ft_strjoin_free(&word, &ln->line[ls->i], word_size, 1);
			++word_size;
		}
		++ls->i;
	}
	return (word);
}
