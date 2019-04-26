/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_dollar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:55:54 by prippa            #+#    #+#             */
/*   Updated: 2019/02/11 12:55:56 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_parser.h"
#include "environ_manipulation.h"

static void	lp_dollar_write(t_line_parser *lp, const char *s, size_t len)
{
	char *key;

	key = ft_strsub(s, 0, len);
	if ((s = env_get_vlu_by_key(sh()->env.start, key)))
		lp_write_to_arg_buf_str(&lp->cmd, s, ft_strlen(s));
	ft_strdel(&key);
}

void		lp_dollar(t_line_parser *lp)
{
	const char	*s;
	size_t		len;

	if (!ft_isalnum_in_case(lp->line[++lp->i]))
	{
		lp_write_to_arg_buf_char(&lp->cmd, lp->line[lp->i - 1]);
		return ;
	}
	s = &lp->line[lp->i];
	if (ft_isalpha_in_case(lp->line[lp->i]))
	{
		len = 1;
		while (ft_isalnum_in_case(lp->line[++lp->i]))
			++len;
		lp_dollar_write(lp, s, len);
	}
	else
		++lp->i;
}
