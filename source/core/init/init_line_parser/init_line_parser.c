/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_line_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 18:09:13 by prippa            #+#    #+#             */
/*   Updated: 2019/04/19 18:09:15 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_parser.h"
#include "syntax_characters.h"

#define KS sizeof(char)
#define VS sizeof(void *)

static void	lp_new_symbol(t_hash_table *h, char key, t_func_cmd value)
{
	char	*k;

	k = ft_memalloc(KS);
	*k = key;
	HT_INSERT_REF(h, k, value, KS, VS);
}

static void	lp_init_pars_manager(void)
{
	t_hash_table *h;

	h = &sh()->pars_manager;
	HT_INIT(h, 0, &ft_cnt_delptr, NULL);
	lp_new_symbol(h, SPACE_C, &lp_space);
	lp_new_symbol(h, DOLLAR_C, &lp_dollar);
	lp_new_symbol(h, SEMICOLON_C, &lp_semicolon);
	lp_new_symbol(h, SINGLE_QUOTES_C, &lp_single_quotes);
	lp_new_symbol(h, DOUBLE_QUOTES_C, &lp_double_quotes);
	lp_new_symbol(h, BACKSLASH_C, &lp_backslash);
	lp_new_symbol(h, TILDE_C, &lp_tilde);
	lp_new_symbol(h, REDIRECT_IN_C, &lp_redirect_in);
	lp_new_symbol(h, REDIRECT_OUT_C, &lp_redirect_out);
	lp_new_symbol(h, PIPE_C, &lp_pipe);
}

void		sh_init_line_parser(void)
{
	lp_init_pars_manager();
}
