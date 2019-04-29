/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_get_cmd_input_word.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 22:13:02 by prippa            #+#    #+#             */
/*   Updated: 2019/04/29 22:15:28 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "auto_completion.h"
#include "syntax_characters.h"

t_bool	rl_t_get_cmd_input_word(t_line *ln)
{
	size_t	len;
	size_t	size;
	t_bool	space_flag;

	size = ln->pc;
	space_flag = false;
	len = 0;
	while (size--)
	{
		if (ln->line[size] == SEMICOLON_C || ln->line[size] == PIPE_C)
			break ;
		if (ft_isspace(ln->line[size]))
			space_flag = true;
		else if (space_flag && ft_isascii(ln->line[size]))
			return (false);
		if (!space_flag)
			++len;
	}
	ac()->input_word = ft_strsub(ln->line, ln->pc - len, len);
	return (true);
}
