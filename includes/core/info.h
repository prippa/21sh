/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 12:31:50 by prippa            #+#    #+#             */
/*   Updated: 2019/04/29 22:45:38 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_H
# define INFO_H

# define SHELL_NAME		"21sh"
# define TERM_TYPE		"xterm-256color"

# define KEY_VALUE_SEPARATOR	'='
# define UNIX_PATH_SEPARATOR	'/'
# define PATH_ENV_SEPARATOR		':'
# define CLOSE_FD				"-"

# define CUR_DIR				"."
# define PREV_DIR				".."

# define HOME_ENV		"HOME"
# define PWD_ENV		"PWD"
# define OLDPWD_ENV		"OLDPWD"
# define PATH_ENV		"PATH"
# define SHELL_ENV		"SHELL"
# define LAST_ARG_ENV	"_"
# define SHELL_LVL_ENV	"SHLVL"
# define TERM_ENV		"TERM"

# define DEFAULT_BIN_PATH	"/bin"

# define CHDIR_FAILED		"chdir() failed"
# define GETCWD_FAILED		"getcwd() failed"
# define FORK_FAILED		"fork() failed"
# define WAIT_FAILED		"wait() failed"
# define TCGETATTR_FAILED	"tcgetattr() failed"
# define TCSETATTR_FAILED	"tcsetattr() failed"
# define DUP2_FAILED		"dup2() failed"
# define PIPE_FAILED		"pipe() failed"

# define PERM_DENIED		"'%s': Permission denied"
# define NO_FILE_OR_DIR		"'%s': No such file or directory"
# define IS_A_DIR			"'%s': Is a directory"
# define TO_MANY_ARGS		"Too many arguments"

# define SH_PERM_DENIED 	SHELL_NAME ": " PERM_DENIED
# define BAD_DESC			SHELL_NAME ": %s: Bad file descriptor"
# define BAD_DESC_N			SHELL_NAME ": %d: Bad file descriptor"

#endif
