#include "shell.h"
#include "signal.h"

void		sh_init_sig_rl(void)
{
	signal(SIGINT, sh_sig_handle_rl);
	signal(SIGWINCH, sh_sig_handle_rl);
}

void		sh_init_sig_base(void)
{
	signal(SIGINT, sh_sig_handle_base);
}

void		sh_init_sig_incase(void)
{
	signal(SIGINT, sh_sig_handle_incase);
}

void		sh_init_sig_default(void)
{
	signal(SIGINT, SIG_DFL);
}
