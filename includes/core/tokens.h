/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 18:06:46 by prippa            #+#    #+#             */
/*   Updated: 2019/04/19 18:06:47 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENS_H
# define TOKENS_H

# include "syntax_characters.h"

# define TOKEN_SIZE 5

static const char	g_tokens[TOKEN_SIZE] =
{
	SEMICOLON_C,
	PIPE_C,
	REDIRECT_IN_C,
	REDIRECT_OUT_C,
	FDA_C
};

#endif
