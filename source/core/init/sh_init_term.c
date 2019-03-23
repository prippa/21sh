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

#include "read_line.h"
#include <fcntl.h>
#include <term.h>
#include "messages.h"

#define NOT_A_TERM "Not a terminal."
#define NO_TERM "Specify a terminal type with 'setenv TERM <yourtype>'."
#define NO_ACCESS_TO_DB "Could not access the termcap data base."
#define NO_SUCH_ENTRY "Terminal type `%s' is not defined."

static void	sh_init_termcaps(void)
{
	t_tc *t;

	t = tc();
	t->le = tgetstr("le", NULL);
	t->nd = tgetstr("nd", NULL);
	t->down = tgetstr("do", NULL);
	t->up = tgetstr("up", NULL);
	t->cd = tgetstr("cd", NULL);
	t->cr = tgetstr("cr", NULL);
	t->ch = tgetstr("ch", NULL);
}

static void	sh_init_new_settings(void)
{
	if ((tcgetattr(STDIN_FILENO, sh()->old_settings)) == ERR)
		sh_fatal_err(TCGETATTR_FAILED);
	if ((tcgetattr(STDIN_FILENO, sh()->new_settings)) == ERR)
		sh_fatal_err(TCGETATTR_FAILED);
	sh()->new_settings->c_lflag &= ~(ICANON | ECHO | ECHONL);
}

void		sh_init_term(void)
{
	int32_t	res;
	char	*term_type;

	if (!isatty(STDIN_FILENO))
		sh_fatal_err(NOT_A_TERM);
	if (!(term_type = getenv("TERM")))
		sh_fatal_err(MSG(NO_TERM, NULL));
	if ((res = tgetent(NULL, term_type)) == ERR)
		sh_fatal_err(NO_ACCESS_TO_DB);
	else if (res == 0)
		sh_fatal_err(MSG(NO_SUCH_ENTRY, term_type));
	sh_init_new_settings();
	sh_init_termcaps();
}
