/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_modify_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 11:10:04 by prippa            #+#    #+#             */
/*   Updated: 2019/03/20 11:10:08 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_line.h"

void		rl_del_from_line(t_line *ln, size_t end,
				uint16_t col, t_bool print_to_term)
{
	size_t	del_sum;
	size_t	rc_size;

	del_sum = end - ln->l_cur_pos;
	GET_MEM(MALLOC_ERR, ln->line, ft_strcut_free,
		&ln->line, ln->l_cur_pos, end);
	ln->l_end -= del_sum;
	if (print_to_term)
	{
		rl_make_tc_magic(tc()->cd);
		rc_size = ft_strlen(ln->line + ln->l_cur_pos);
		ft_putstr_fd(ln->line + ln->l_cur_pos, STDIN_FILENO);
		rl_determine_x(ln, rc_size, col);
		rl_move_cursor_left(ln, ln->l_cur_pos + rc_size, rc_size, col);
	}
}

void		rl_add_to_line(t_line *ln, const char *src,
				uint16_t col, t_bool print_to_term)
{
	size_t	src_len;
	size_t	rc_size;

	src_len = ft_strlen(src);
	GET_MEM(MALLOC_ERR, ln->line, ft_strinsert_free,
		&ln->line, src, ln->l_cur_pos);
	ln->l_end += src_len;
	ln->l_cur_pos += src_len;
	if (print_to_term)
	{
		rc_size = ft_strlen(ln->line + ln->l_cur_pos);
		ft_putstr_fd(src, STDIN_FILENO);
		ft_putstr_fd(ln->line + ln->l_cur_pos, STDIN_FILENO);
		rl_determine_x(ln, src_len + rc_size, col);
		rl_move_cursor_left(ln, ln->l_cur_pos + rc_size, rc_size, col);
	}
}
