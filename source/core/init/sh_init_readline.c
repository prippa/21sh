#include "button_keys.h"

#define KS sizeof(uint64_t)
#define VS sizeof(t_ke_event)
#define KE(k) (uint64_t[]){k}

static void	rl_new_event(t_hash_table *h, uint64_t k, t_ke_event value)
{
	uint64_t *key;

	key = ft_memalloc(KS);
	*key = k;
	HT_INSERT_REF(h, key, value, KS, VS);
}

static void	rl_init_bonus_events(t_hash_table *h)
{
	rl_new_event(h, KEY_TAB, &rl_ke_tab);
	rl_new_event(h, KEY_CTRL_A, &rl_ke_ctrl_a);
	rl_new_event(h, KEY_CTRL_E, &rl_ke_ctrl_e);
	rl_new_event(h, KEY_CTRL_G, &rl_ke_ctrl_g);
	rl_new_event(h, KEY_CTRL_U, &rl_ke_ctrl_u);
	rl_new_event(h, KEY_CTRL_K, &rl_ke_ctrl_k);
	rl_new_event(h, KEY_CTRL_H, &rl_ke_ctrl_h);
	rl_new_event(h, KEY_CTRL_L, &rl_ke_ctrl_l);
	rl_new_event(h, KEY_CTRL_R, &rl_ke_ctrl_r);
	rl_new_event(h, KEY_CTRL_SHIFT_LEFT, &rl_ke_ctrl_shift_left);
	rl_new_event(h, KEY_CTRL_SHIFT_RIGHT, &rl_ke_ctrl_shift_right);
	rl_new_event(h, KEY_CTRL_SHIFT_UP, &rl_ke_ctrl_shift_up);
	rl_new_event(h, KEY_CTRL_SHIFT_DOWN, &rl_ke_ctrl_shift_down);
}

static void	rl_init_base_events(t_hash_table *h)
{
	rl_new_event(h, KEY_BACKSPACE, &rl_ke_backspace);
	rl_new_event(h, KEY_DELETE, &rl_ke_delete);
	rl_new_event(h, KEY_RETURN, &rl_ke_return);
	rl_new_event(h, KEY_HOME, &rl_ke_home);
	rl_new_event(h, KEY_END, &rl_ke_end);
	rl_new_event(h, KEY_LEFT, &rl_ke_left);
	rl_new_event(h, KEY_RIGHT, &rl_ke_right);
	rl_new_event(h, KEY_UP, &rl_ke_up);
	rl_new_event(h, KEY_DOWN, &rl_ke_down);
	rl_new_event(h, KEY_CTRL_LEFT, &rl_ke_ctrl_left);
	rl_new_event(h, KEY_CTRL_RIGHT, &rl_ke_ctrl_right);
	rl_new_event(h, KEY_CTRL_UP, &rl_ke_ctrl_up);
	rl_new_event(h, KEY_CTRL_DOWN, &rl_ke_ctrl_down);
	rl_new_event(h, KEY_CTRL_D, &rl_ke_ctrl_d);
}

void		sh_init_readline(void)
{
	t_hash_table *h;

	h = &rl()->button_keys;
	HT_INIT(h, KE_SIZE * HT_ELEM_SPACE, &ft_cnt_delptr, NULL);
	rl_init_base_events(h);
	rl_init_bonus_events(h);
}
