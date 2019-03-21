/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_join_new_data_to_line.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 11:10:04 by prippa            #+#    #+#             */
/*   Updated: 2019/03/20 11:10:08 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_line.h"

void		rl_jnd_to_line(t_line *ln, const char *src)
{
	size_t	src_len;
	// size_t	right_index;

	src_len = ft_strlen(src);
	GET_MEM(MALLOC_ERR, ln->line, ft_strinsert_free,
		&ln->line, src, ln->cursor_pos);
	ln->line_len += src_len;
	ln->cursor_pos += src_len;
	ft_putstr_fd(src, STDIN_FILENO);
	rl_move_cursor(ln, MV_LEFT, 1);
	// right_index = ln->line_len - ln->cursor_pos;
	// rl_do_magic(right_index);
	// ln->cursor_pos += right_index;
	// rl_move_cursor(ln, MV_LEFT, right_index);
	// ft_putstr_fd(&ln->line[ln->cursor_pos], STDIN_FILENO);
	// ln->cursor_pos += ft_strlen(&ln->line[ln->cursor_pos]);
	// rl_move_cursor(ln, MV_LEFT, right_index);
}
