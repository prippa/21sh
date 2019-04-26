/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_fd_manipulations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 11:52:43 by prippa            #+#    #+#             */
/*   Updated: 2019/04/24 11:52:44 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_parser.h"
#include "info.h"

void	lp_reset_fd(void)
{
	if (dup2(TERM_STDIN, STDIN_FILENO) == ERR)
		g_fef(DUP2_FAILED);
	if (dup2(TERM_STDOUT, STDOUT_FILENO) == ERR)
		g_fef(DUP2_FAILED);
	if (dup2(TERM_STDERR, STDERR_FILENO) == ERR)
		g_fef(DUP2_FAILED);
}

void	lp_close_fd_list(t_list *fd)
{
	t_list_elem *start;
	t_dup2_fd	*fds;

	start = fd->start;
	while (start)
	{
		fds = (t_dup2_fd *)start->content;
		if (lp_is_valid_fd(fds->fildes))
			close(fds->fildes);
		if (lp_is_valid_fd(fds->fildes2))
			close(fds->fildes2);
		start = start->next;
	}
}

t_bool	lp_is_valid_fd(int32_t fd)
{
	if (fd == TERM_STDIN || fd == TERM_STDOUT || fd == TERM_STDERR ||
		fd == TERM_PIPE)
		return (false);
	return (true);
}
