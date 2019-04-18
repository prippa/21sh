#include "shell.h"
#include "tokens.h"

static t_bool sh_is_token(char c)
{
	uint8_t	i;

	i = -1;
	while (++i < TOKEN_SIZE)
		if (c == g_tokens[i])
			return (true);
	return (false);
}

static void	sh_gw_sq_valid(size_t *i, const char *line,
				char **word, size_t *word_size)
{
	const char	*start;
	size_t		len;

	start = &line[++*i];
	len = 0;
	while (line[*i])
	{
		if (line[*i] == SINGLE_QUOTES_C)
			break ;
		++len;
		++*i;
	}
	if (len)
	{
		ft_strjoin_free(word, start, *word_size, len);
		*word_size += len;
	}
}

static void	sh_gw_bs_valid(size_t *i, const char *line,
				char **word, size_t *word_size)
{
	ft_strjoin_free(word, &line[++*i], *word_size, 1);
	*word_size += 1;
}

static void	sh_gw_dq_valid(size_t *i, const char *line,
				char **word, size_t *word_size)
{
	++*i;
	while (line[*i])
	{
		if (line[*i] == DOUBLE_QUOTES_C)
			break ;
		if (line[*i] == BACKSLASH_C)
			sh_gw_bs_valid(i, line, word, word_size);
		else
		{
			ft_strjoin_free(word, &line[*i], *word_size, 1);
			*word_size += 1;
		}
		++*i;
	}
}

char		*sh_get_word(size_t *i, const char *line)
{
	char	*word;
	size_t	word_size;

	word = ft_strdup(EMPTY_STR);
	word_size = 0;
	while (ft_isspace(line[*i]))
		++*i;
	while (line[*i])
	{
		if (sh_is_token(line[*i]) || ft_isspace(line[*i]))
			break ;
		if (line[*i] == SINGLE_QUOTES_C)
			sh_gw_sq_valid(i, line, &word, &word_size);
		else if (line[*i] == DOUBLE_QUOTES_C)
			sh_gw_dq_valid(i, line, &word, &word_size);
		else if (line[*i] == BACKSLASH_C)
			sh_gw_bs_valid(i, line, &word, &word_size);
		else
		{
			ft_strjoin_free(&word, &line[*i], word_size, 1);
			++word_size;
		}
		++*i;
	}
	return (word);
}
