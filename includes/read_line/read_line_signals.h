/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line_signals.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:03:56 by prippa            #+#    #+#             */
/*   Updated: 2019/03/28 16:03:58 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_LINE_SIGNALS_H
# define READ_LINE_SIGNALS_H

# include <stdint.h>
# include <signal.h>

struct			s_sig_box
{
	t_bool		flag;
	int32_t		sig;
};

void			rl_init_sig(void);
void			rl_init_sig_aside(void);
void			rl_sig_handle(int32_t sig);
void			rl_execute_aside_signals(sig_t sig_h);

#endif
