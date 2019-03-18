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

# define KEY_UP			4283163
# define KEY_DOWN		4348699
# define KEY_RIGHT		4414235
# define KEY_LEFT		4479771
# define KEY_RETURN		10
# define KEY_SPACE		32
# define KEY_BACK_SPACE	127
# define KEY_DEL		2117294875
# define KEY_CTRL_A		1
# define KEY_CTRL_W		23

# define UP buf[0] == 27 && buf[1] == 91 && buf[2] == 65
# define DOWN buf[0] == 27 && buf[1] == 91 && buf[2] == 66
# define RIGHT buf[0] == 27 && buf[1] == 91 && buf[2] == 67
# define LEFT buf[0] == 27 && buf[1] == 91 && buf[2] == 68

# define WTF_UP buf[0] == 27 && buf[1] == 91 && buf[2] == 72
# define WTF_DOWN buf[0] == 27 && buf[1] == 91 && buf[2] == 70

# define TAB buf[0] == 9
# define BACK_SPACE buf[0] == 127
# define CTRL_D buf[0] == 4
# define NEW_LINE buf[0] == 10

void			rl_ke_back_space(void);
void			rl_ke_ctrl_d(void);
int32_t			rl_ke_return(void);
void			rl_ke_tab(void);

void			tab_process_matches(const t_list *m, size_t len);

#endif
