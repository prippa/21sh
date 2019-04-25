/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:34:00 by prippa            #+#    #+#             */
/*   Updated: 2018/10/04 12:34:02 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "libft.h"
# include "ft_printf.h"
# include "ft_list.h"
# include "ft_hash_table.h"
# include <stdio.h>
# include <termios.h>

# define PATH_MAX			4096
# define PROMPT_ADS			5
# define PROMPT_COLORS_SIZE	100
# define PROMPT_SIZE		FILENAME_MAX + PROMPT_ADS + PROMPT_COLORS_SIZE

enum {TERM_STDIN = 100, TERM_STDOUT, TERM_STDERR, TERM_PIPE};

typedef struct		s_shell
{
	t_list			env;
	t_hash_table	bin_path;
	t_hash_table	pars_manager;
	struct termios	old_settings;
	struct termios	new_settings;
	char			prompt[PROMPT_SIZE + 1];
	char			curent_path[PATH_MAX + 1];
	char			*line;
	t_bool			env_exec_flag;
	t_bool			ok;
	int32_t			exec_code;
	char			*pwd;
	size_t			pid_len;
}					t_shell;

t_shell				*sh(void);

void				sh_fatal_err(const char *message);
void				sh_print_err(int32_t err_code, char *message);

void				sh_init(void);
void				sh_init_env(void);
void				sh_init_term(void);
void				sh_init_read_line(void);
void				sh_init_rl_histiry(void);
void				sh_init_line_parser(void);

t_bool				sh_is_dir(const char *path);
t_bool				sh_is_valid_path(const char *path);

t_bool				sh_path_access(const char *path, const char *prefix);
char				*sh_join_path_to_pwd(const char *cur_pwd, const char *path);
void				sh_update_curent_dir_name(void);
void				sh_update_prompt(t_bool ok);
void				sh_reset_settings(void);

char				*read_line(void);

void				line_parser(void);

void				sh_sigint_base_reaction(void);
void				sh_sig_handle_base(int32_t sig);
void				sh_sig_handle_incase(int32_t sig);
void				sh_init_sig_base(void);
void				sh_init_sig_incase(void);
void				sh_init_sig_default(void);

char				*sh_get_word(size_t *i, const char *line);

#endif
