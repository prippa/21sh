/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parser.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:49:33 by prippa            #+#    #+#             */
/*   Updated: 2019/01/12 18:49:34 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_PARSER_H
# define LINE_PARSER_H

# include "shell.h"

# define ARG_BUF_SIZE	4096

typedef struct	s_redirect
{
	int32_t		fd;
	t_bool		append_flag;
	t_bool		desc_flag;
	char		*word;
}				t_redirect;

typedef struct	s_line_parser
{
	const char	*line;
	size_t		i;
	t_list		args_list;
	char		arg_buf[ARG_BUF_SIZE + 1];
	size_t		arg_buf_len;
	char		*arg;
	size_t		arg_len;
}				t_line_parser;

void			lp_reset_fd(int32_t fd[3]);

void			lp_join_to_arg(t_line_parser *lp, const char *src, size_t len);
void			lp_write_to_arg_buf_str(t_line_parser *lp,
					const char *src, size_t len);
void			lp_write_to_arg_buf_char(t_line_parser *lp, char c);

void			lp_push_arg(t_line_parser *lp);
void			lp_push_command(t_line_parser *lp);

typedef void	(*t_func_cmd)(t_line_parser *lp);
void			lp_dollar(t_line_parser *lp);
void			lp_backslash(t_line_parser *lp);
void			lp_single_quotes(t_line_parser *lp);
void			lp_double_quotes(t_line_parser *lp);
void			lp_space(t_line_parser *lp);
void			lp_semicolon(t_line_parser *lp);
void			lp_tilde(t_line_parser *lp);

void			lp_redirect_in(t_line_parser *lp);
void			lp_redirect_out(t_line_parser *lp);
void			lp_pipe(t_line_parser *lp);

t_bool			lp_check_rediraction(t_line_parser *lp);
int32_t			lp_rdr_get_file_desc(t_line_parser *lp);
t_bool			lp_is_not_global_fd(int32_t fd, int32_t global_fd[3]);
t_bool			lp_rdr_valid_word(const char *word);
t_redirect		lp_init_rdr(t_redirect *rdr, t_line_parser *lp);

#endif
