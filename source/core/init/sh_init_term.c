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

/*
** ch - position the cursor at column c in the same line it is on.
** up - move cursor up by one row
** do - move cursor down by one row
** cr - move cursor to the beginning of the row
** cd - clear the line the cursor is on, and all the lines below it,
**      down to the bottom of the screen.
** cl - clear the entire screen and position the cursor at the upper left corner
** u7 - cursor position request (equiv. to VT100/ANSI/ECMA-48 DSR 6)
*/

static void	sh_init_termcaps(void)
{
	t_tc *t;

	t = tc();
	t->ch = tgetstr("ch", NULL);
	t->up = tgetstr("up", NULL);
	t->down = tgetstr("do", NULL);
	t->cr = tgetstr("cr", NULL);
	t->cd = tgetstr("cd", NULL);
	t->cl = tgetstr("cl", NULL);
	t->u7 = tgetstr("u7", NULL);
}

static void	sh_init_new_settings(void)
{
	if ((tcgetattr(STDIN_FILENO, &sh()->old_settings)) == ERR)
		sh_fatal_err(TCGETATTR_FAILED);
	if ((tcgetattr(STDIN_FILENO, &sh()->new_settings)) == ERR)
		sh_fatal_err(TCGETATTR_FAILED);
	sh()->new_settings.c_lflag &= ~(ICANON | ECHO | ECHONL);
}

void		sh_init_term(void)
{
	int32_t	res;
	char	*term_type;

	if (!isatty(STDIN_FILENO))
		ft_fatal_err_exit(NOT_A_TERM);
	if (!(term_type = getenv("TERM")))
		ft_fatal_err_exit(NO_TERM);
	if ((res = tgetent(NULL, term_type)) == ERR)
		ft_fatal_err_exit(NO_ACCESS_TO_DB);
	else if (res == 0)
		ft_fatal_err_exit(MSG(NO_SUCH_ENTRY, term_type));
	sh_init_new_settings();
	sh_init_termcaps();
}
