/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_keys.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 17:21:26 by prippa            #+#    #+#             */
/*   Updated: 2019/03/17 17:21:58 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUTTON_KEYS_H
# define BUTTON_KEYS_H

# include "read_line.h"

# define KE_SIZE				27

# define KEY_BACKSPACE			127
# define KEY_DELETE				2117294875
# define KEY_RETURN				10
# define KEY_HOME				4741915
# define KEY_END				4610843
# define KEY_TAB				9

# define KEY_LEFT				4479771
# define KEY_RIGHT				4414235
# define KEY_UP					4283163
# define KEY_DOWN				4348699
# define KEY_CTRL_LEFT			74995417045787
# define KEY_CTRL_RIGHT			73895905418011
# define KEY_CTRL_UP			71696882162459
# define KEY_CTRL_DOWN			72796393790235
# define KEY_CTRL_SHIFT_LEFT	74999712013083
# define KEY_CTRL_SHIFT_RIGHT	73900200385307
# define KEY_CTRL_SHIFT_UP		71701177129755
# define KEY_CTRL_SHIFT_DOWN	72800688757531

# define KEY_CTRL_D				4
# define KEY_CTRL_A				1
# define KEY_CTRL_E				5
# define KEY_CTRL_G				7
# define KEY_CTRL_U				21
# define KEY_CTRL_K				11
# define KEY_CTRL_H				8
# define KEY_CTRL_L				12
# define KEY_CTRL_R				18

int32_t					rl_ke_back_space(t_line *ln);
int32_t					rl_ke_delete(t_line *ln);
int32_t					rl_ke_return(t_line *ln);
int32_t					rl_ke_home(t_line *ln);
int32_t					rl_ke_end(t_line *ln);
int32_t					rl_ke_tab(t_line *ln);
int32_t					tab_process_matches(const t_list *m,
							size_t len, t_line *ln);
int32_t					rl_ke_left(t_line *ln);
int32_t					rl_ke_right(t_line *ln);
int32_t					rl_ke_up(t_line *ln);
int32_t					rl_ke_down(t_line *ln);
int32_t					rl_ke_ctrl_left(t_line *ln);
int32_t					rl_ke_ctrl_right(t_line *ln);
int32_t					rl_ke_ctrl_up(t_line *ln);
int32_t					rl_ke_ctrl_down(t_line *ln);
int32_t					rl_ke_ctrl_shift_left(t_line *ln);
int32_t					rl_ke_ctrl_shift_right(t_line *ln);
int32_t					rl_ke_ctrl_shift_up(t_line *ln);
int32_t					rl_ke_ctrl_shift_down(t_line *ln);
int32_t					rl_ke_ctrl_d(t_line *ln);
int32_t					rl_ke_ctrl_a(t_line *ln);
int32_t					rl_ke_ctrl_e(t_line *ln);
int32_t					rl_ke_ctrl_g(t_line *ln);
int32_t					rl_ke_ctrl_u(t_line *ln);
int32_t					rl_ke_ctrl_k(t_line *ln);
int32_t					rl_ke_ctrl_h(t_line *ln);
int32_t					rl_ke_ctrl_l(t_line *ln);
int32_t					rl_ke_ctrl_r(t_line *ln);

#endif
