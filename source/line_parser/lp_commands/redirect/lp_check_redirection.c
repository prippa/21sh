#include "line_parser.h"
#include "syntax_characters.h"

t_bool		lp_check_rediraction(t_line_parser *lp)
{
	size_t		i;

	i = lp->i;
	while (ft_isdigit(lp->line[++i]))
		;
	if (lp->line[i] == REDIRECT_IN_C || lp->line[i] == REDIRECT_OUT_C)
	{
		if (lp->line[i] == REDIRECT_IN_C)
			lp_redirect_in(lp);
		if (lp->line[i] == REDIRECT_OUT_C)
			lp_redirect_out(lp);
		return (true);
	}
	return (false);
}
