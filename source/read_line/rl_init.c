#include "read_line.h"

void		rl_init(void)
{
	ft_bzero(rl(), sizeof(t_read_line));
	ft_putstr_fd(sh()->prompt, STDIN_FILENO);
	ioctl(STDIN_FILENO, TIOCGWINSZ, &rl()->w_size);
	rl_increase_x(&rl()->ln, P_SIZE, rl()->w_size.ws_col);
}
