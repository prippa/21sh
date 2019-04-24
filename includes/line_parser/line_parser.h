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
	t_bool		mod_flag;
	t_bool		fda_flag;
	char		*word;
}				t_redirect;

typedef struct	s_dup2_fd
{
	int32_t		fildes;
	int32_t		fildes2;
}				t_dup2_fd;
# define FD(fd, fd2) &(t_dup2_fd){.fildes = fd, .fildes2 = fd2}

typedef struct	s_command
{
	char		*error;
	t_list		fd_list;
	t_list		args_list;
	char		arg_buf[ARG_BUF_SIZE + 1];
	size_t		arg_buf_len;
	char		*arg;
	size_t		arg_len;
}				t_command;

typedef struct	s_line_parser
{
	const char	*line;
	size_t		i;
	t_list		cmds;
	t_command	cmd;
}				t_line_parser;

void			lp_join_to_arg(t_command *cmd, const char *src, size_t len);
void			lp_write_to_arg_buf_str(t_command *cmd,
					const char *src, size_t len);
void			lp_write_to_arg_buf_char(t_command *cmd, char c);
void			lp_add_arg(t_command *cmd);

void			lp_del_commands_list(void *content, size_t content_size);
void			lp_init_commnd(t_command *cmd);
void			lp_add_cmd(t_line_parser *lp);
char			**lp_get_command(t_command *cmd);
void			lp_run_command(char **args);

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
t_bool			lp_rdr_check_word_permision(const char *word,
					int32_t file_perm, t_command *cmd);
void			lp_init_rdr(t_redirect *rdr,
					t_line_parser *lp, int32_t base_fd);
void			lp_rdr_redirect_desc(t_redirect *rdr, t_command *cmd);
void			lp_rdr_init_flags(t_line_parser *lp, t_redirect *rdr, char c);

void			lp_reset_fd(void);
void			lp_close_fd_list(t_list *fd);
t_bool			lp_is_valid_fd(int32_t fd);

#endif
