/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 17:21:26 by prippa            #+#    #+#             */
/*   Updated: 2019/03/17 17:21:58 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# include "read_line.h"

# define KE_SIZE		14

# define KEY_LEFT		4479771
# define KEY_RIGHT		4414235
# define KEY_UP			4283163
# define KEY_DOWN		4348699
int32_t					rl_ke_left(t_cursor *cur);
int32_t					rl_ke_right(t_cursor *cur);
int32_t					rl_ke_up(t_cursor *cur);
int32_t					rl_ke_down(t_cursor *cur);

# define KEY_RETURN		10
int32_t					rl_ke_return(t_cursor *cur);

# define KEY_BACK_SPACE	127
# define KEY_DELETE		2117294875
int32_t					rl_ke_back_space(t_cursor *cur);
int32_t					rl_ke_delete(t_cursor *cur);

# define KEY_CTRL_D		4
# define KEY_CTRL_A		1
int32_t					rl_ke_ctrl_d(t_cursor *cur);
int32_t					rl_ke_ctrl_a(t_cursor *cur);

# define KEY_ALT_LEFT	1146821403
# define KEY_ALT_RIGHT	1130044187
# define KEY_ALT_UP		1096489755
# define KEY_ALT_DOWN	1113266971
int32_t					rl_ke_alt_left(t_cursor *cur);
int32_t					rl_ke_alt_right(t_cursor *cur);
int32_t					rl_ke_alt_up(t_cursor *cur);
int32_t					rl_ke_alt_down(t_cursor *cur);

# define KEY_TAB		9
int32_t					rl_ke_tab(t_cursor *cur);
void					tab_process_matches(const t_list *m, size_t len);

void					rl_ke_goto(int32_t x, int32_t y);

#endif
