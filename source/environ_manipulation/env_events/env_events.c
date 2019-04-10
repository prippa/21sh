#include "environ_manipulation.h"
#include "messages.h"
#include "shell.h"

void	env_check_global_event(const t_env *e)
{
	if (sh()->env_exec_flag)
		return ;
	if (ft_strequ(e->key, PATH_ENV))
		env_new_path(e->value);
	if (ft_strequ(e->key, HOME_ENV))
		sh_update_curent_dir_name();
}
