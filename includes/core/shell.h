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
# include <stdio.h>
# include <termios.h>

# define PATH_MAX			4096
# define PROMPT_ADS			5
# define PROMPT_COLORS_SIZE	100
# define PROMPT_SIZE		FILENAME_MAX + PROMPT_ADS + PROMPT_COLORS_SIZE

typedef struct		s_shell
{
	t_list			env;
	struct termios	old_settings;
	struct termios	new_settings;
	char			prompt[PROMPT_SIZE + 1];
	char			curent_path[PATH_MAX + 1];
	char			*line;
	size_t			i;
	t_bool			env_exec_flag;
	t_bool			ok;
	int32_t			exec_code;
	char			*pwd;
}					t_shell;

t_shell				*sh(void);

# define PE_P(f, a ...) ft_dprintf(STDERR_FILENO, f, a)
# define PE_NL ft_putendl_fd(EMPTY_STR, STDERR_FILENO)
# define PE_SE(ec) sh()->exec_code = ec; sh()->ok = false
# define PRINT_ERR(ec, f, a ...) PE_P(f, a); PE_NL; PE_SE(ec)

void				sh_fatal_err(const char *message);

void				sh_init(void);
void				sh_init_env(void);
void				sh_init_term(void);

t_bool				sh_is_dir(const char *path);
t_bool				sh_is_valid_path(const char *path);

t_bool				sh_path_access(const char *path, const char *prefix);
char				*sh_join_path_to_pwd(const char *cur_pwd, const char *path);
void				sh_update_curent_dir_name(void);
void				sh_update_prompt(t_bool ok);
void				sh_reset_settings(void);
void				sh_lstpush_back(t_list *lst, t_bool make_copy_of_content,
						void *content, size_t content_size);

char				*read_line(void);

void				line_parser(void);

void				sh_sigint_base_reaction(void);
void				sh_sig_handle_base(int32_t sig);
void				sh_sig_handle_incase(int32_t sig);
void				sh_init_sig_base(void);
void				sh_init_sig_incase(void);
void				sh_init_sig_default(void);

#endif
