/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:34:00 by prippa            #+#    #+#             */
/*   Updated: 2019/04/30 01:03:43 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "libft.h"
# include "ft_printf.h"
# include "ft_list.h"
# include "ft_hash_table.h"
# include <termios.h>
# include <limits.h>
# include <stdio.h>

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
	char			current_path[PATH_MAX + 1];
	char			*line;
	t_bool			env_exec_flag;
	t_bool			ok;
	int32_t			exec_code;
	char			*pwd;
	size_t			childs_count;
}					t_shell;

t_shell				*sh(void);

void				sh_fatal_err(const char *message);
void				sh_print_err(int32_t err_code, char *message);

void				sh_init(void);
void				sh_init_env(void);
void				sh_init_term(void);
void				sh_init_read_line(void);
void				sh_init_rl_history(void);
void				sh_init_line_parser(void);

t_bool				sh_is_dir(const char *path);
t_bool				sh_is_valid_path_len(const char *path);

t_bool				sh_path_access(const char *path, const char *prefix);
char				*sh_join_path_to_pwd(const char *cur_pwd, const char *path);
void				sh_update_current_dir_name(void);
void				sh_update_prompt(t_bool ok);
void				sh_reset_settings(void);

char				*read_line(void);

void				line_parser(void);

void				sh_sigint_reaction(void);
void				sh_init_signals(void);
void				sh_reset_signals(void);

char				*sh_get_word(size_t *i, const char *line);

#endif
