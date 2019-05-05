/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 20:18:20 by prippa            #+#    #+#             */
/*   Updated: 2019/05/05 18:39:07 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "ft_list.h"
# include "ft_def.h"

typedef struct	s_builtin
{
	t_list		*env;
	char		**args;
}				t_build;

void			sh_cd(t_build *b);
void			sh_echo(t_build *b);
void			sh_env(t_build *b);
void			sh_setenv(t_build *b);
void			sh_unsetenv(t_build *b);
void			sh_exit(t_build *b);
void			sh_hash(t_build *b);

int32_t			sh_setenv_one_env(t_list *env_list,
					const char *env, t_bool strictly_valid_flag);
void			sh_process_cmd(t_build *b, const char *cmd_prefix);
void			sh_exec(const char *path, t_build *b);
t_bool			sh_check_path(const char *path, size_t path_len, t_build *b);
t_bool			sh_check_full_path(const char *full_path,
					size_t len, t_build *b);

# define SH_BUILTIN_SIZE	7

# define CD_CMD			"cd"
# define ECHO_CMD		"echo"
# define ENV_CMD		"env"
# define SETENV_CMD		"setenv"
# define UNSETENV_CMD	"unsetenv"
# define EXIT_CMD		"exit"
# define HASH_CMD		"hash"

#endif
