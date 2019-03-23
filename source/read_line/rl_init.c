/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 18:35:36 by prippa            #+#    #+#             */
/*   Updated: 2019/03/23 18:35:37 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_line.h"

t_read_line	*rl(void)
{
	static t_read_line rl;

	return (&rl);
}

t_tc		*tc(void)
{
	static t_tc tc;

	return (&tc);
}

void		rl_init(void)
{
	t_read_line *r;

	r = rl();
	ft_bzero(r, sizeof(t_read_line));
	r->prompt_size = PROMPT_ADS + ft_strlen(sh()->curent_path);
	ft_putstr_fd(sh()->prompt, STDIN_FILENO);
	ioctl(STDIN_FILENO, TIOCGWINSZ, &r->w_size);
	rl_determine_x(&r->ln, r->prompt_size, r->w_size.ws_col);
}
