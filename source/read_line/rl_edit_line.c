/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_edit_line.c                                     :+:      :+:    :+:   */
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
	size_t	rc_size;

	if (end > ln->l_end)
		end = ln->l_end;
	GET_MEM(MALLOC_ERR, ln->line, ft_strcut_free, &ln->line, ln->pc, end);
	ln->l_end -= end - ln->pc;
	if (print_to_term)
	{
		rl_make_tc_magic(tc()->cd);
		ft_putstr_fd(ln->line + ln->pc, STDIN_FILENO);
		rc_size = ft_strlen(ln->line + ln->pc);
		rl_determine_x(ln, col);
		rl_move_cursor_left(ln, ln->pc + rc_size, rc_size, col);
	}
}

void		rl_add_to_line(t_line *ln, const char *src,
				uint16_t col, t_bool print_to_term)
{
	size_t	src_len;
	size_t	rc_size;

	if (!src)
		return ;
	src_len = ft_strlen(src);
	GET_MEM(MALLOC_ERR, ln->line, ft_strinsert_free, &ln->line, src, ln->pc);
	ln->l_end += src_len;
	ln->pc += src_len;
	if (print_to_term)
	{
		ft_putstr_fd(src, STDIN_FILENO);
		ft_putstr_fd(ln->line + ln->pc, STDIN_FILENO);
		rc_size = ft_strlen(ln->line + ln->pc);
		rl_determine_x(ln, col);
		rl_move_cursor_left(ln, ln->pc + rc_size, rc_size, col);
	}
}

void		rl_line_del(t_line *ln)
{
	ft_memdel((void **)&ln->line);
}

void		rl_line_cpy(t_line *dst, t_line *src)
{
	rl_line_del(dst);
	ft_memcpy(dst, src, sizeof(t_line));
	if (src->line)
	{
		GET_MEM(MALLOC_ERR, dst->line, ft_strdup, src->line);
	}
}
