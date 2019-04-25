/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_init_term.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 17:39:40 by prippa            #+#    #+#             */
/*   Updated: 2019/03/17 17:39:42 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include <term.h>
#include "messages.h"
#include "environ_manipulation.h"

#define NOT_A_TERM "Not a terminal."
#define NO_TERM "Specify a terminal type with 'setenv TERM <yourtype>'."
#define NO_ACCESS_TO_DB "Could not access the termcap data base."
#define NO_SUCH_ENTRY "Terminal type `%s' is not defined."

static void	sh_init_new_settings(void)
{
	if ((tcgetattr(STDIN_FILENO, &sh()->old_settings)) == ERR)
		g_fef(TCGETATTR_FAILED);
	if ((tcgetattr(STDIN_FILENO, &sh()->new_settings)) == ERR)
		g_fef(TCGETATTR_FAILED);
	sh()->new_settings.c_lflag &= ~(ICANON | ECHO | ECHONL);
}

static void	sh_init_term_fd(void)
{
	if (dup2(STDIN_FILENO, TERM_STDIN) == ERR)
		g_fef(DUP2_FAILED);
	if (dup2(STDOUT_FILENO, TERM_STDOUT) == ERR)
		g_fef(DUP2_FAILED);
	if (dup2(STDERR_FILENO, TERM_STDERR) == ERR)
		g_fef(DUP2_FAILED);
}

void		sh_init_term(void)
{
	int32_t	res;
	char	*term_type;

	if (!isatty(STDIN_FILENO))
		g_fef(NOT_A_TERM);
	if (!(term_type = env_get_vlu_by_key(sh()->env.start, TERM_ENV)))
		g_fef(NO_TERM);
	if ((res = tgetent(NULL, term_type)) == ERR)
		g_fef(NO_ACCESS_TO_DB);
	else if (res == 0)
		g_fef(MSG(NO_SUCH_ENTRY, term_type));
	sh_init_new_settings();
	sh_init_term_fd();
}
