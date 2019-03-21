/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_move_cursor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 11:10:33 by prippa            #+#    #+#             */
/*   Updated: 2019/03/20 11:10:34 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_line.h"

t_bool			rl_move_cursor(t_line *ln, t_motion_vector mv, size_t len)
{
	t_bool			op_res;
	t_tc			*t;

	t = tc();
	// system("clear");
	tputs(t->up, 0, &sl_print_key);
	sleep(1);
	ft_putstr_fd("lol1", 0);
	tputs(t->up, 0, &sl_print_key);
	sleep(1);
	ft_putstr_fd("lol2", 0);
	tputs(t->up, 0, &sl_print_key);
	sleep(1);
	ft_putstr_fd("lol3", 0);
	tputs(t->up, 0, &sl_print_key);
	sleep(1);
	ft_putstr_fd("lol4", 0);
	tputs(t->up, 0, &sl_print_key);
	sleep(1);
	ft_putstr_fd("lol5", 0);
	sleep(2);
	// tputs(TC_IM, 0, &sl_print_key);
	// ft_putstr_fd("aaaaaaaaaa", 0);
	// sleep(1);
	// tputs(TC_LE, 0, &sl_print_key);
	// tputs(TC_LE, 0, &sl_print_key);
	// tputs(TC_LE, 0, &sl_print_key);
	// tputs(TC_LE, 0, &sl_print_key);
	// tputs(TC_LE, 0, &sl_print_key);
	// tputs(TC_LE, 0, &sl_print_key);
	// tputs(TC_LE, 0, &sl_print_key);
	// tputs(TC_LE, 0, &sl_print_key);
	// tputs(TC_LE, 0, &sl_print_key);
	// tputs(TC_LE, 0, &sl_print_key);
	// ft_putstr_fd("gggggggggg", 0);
	// sleep(2);
	// tputs(TC_EI, 0, &sl_print_key);
	// ft_putstr_fd("123", 0);
	// sleep(1);
	// tputs(TC_ND, 0, &sl_print_key);
	// tputs(TC_ND, 0, &sl_print_key);
	// tputs(TC_ND, 0, &sl_print_key);
	// tputs(TC_ND, 0, &sl_print_key);
	// tputs(TC_ND, 0, &sl_print_key);
	// tputs(TC_ND, 0, &sl_print_key);
	// tputs(TC_ND, 0, &sl_print_key);
	// tputs(TC_ND, 0, &sl_print_key);
	// tputs(TC_ND, 0, &sl_print_key);
	// tputs(TC_ND, 0, &sl_print_key);
	// tputs(TC_ND, 0, &sl_print_key);
	// tputs(TC_ND, 0, &sl_print_key);
	// tputs(TC_ND, 0, &sl_print_key);
	// tputs(TC_ND, 0, &sl_print_key);
	// tputs(TC_ND, 0, &sl_print_key);
	// sleep(1);
	// tputs(TC_DO, 0, &sl_print_key);
	// sleep(1);
	// tputs(TC_UP, 0, &sl_print_key);
	// sleep(1);
	// tputs(TC_ND, 0, &sl_print_key);
	// sleep(1);
	// tputs(TC_DC, 0, &sl_print_key);
	// sleep(2);
	#include "builtin.h"
	sh_exit(NULL);
	op_res = false;
	return (op_res);
}
