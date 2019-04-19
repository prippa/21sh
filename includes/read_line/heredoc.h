/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 18:06:52 by prippa            #+#    #+#             */
/*   Updated: 2019/04/19 18:06:53 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "line_syntax.h"

typedef struct		s_heredoc
{
	t_list			heredoc;
	char			*heredoc_delimiter;
	t_line_syntax	syntax_2;
	size_t			end;
	size_t			start;
}					t_heredoc;

t_heredoc			*hd(void);
t_lexer_status		hd_init(t_line_syntax *ls, t_line *ln);
t_bool				hd_continue(t_line *ln);
void				hd_close(t_line *ln);

#endif
