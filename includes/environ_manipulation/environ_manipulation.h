/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ_manipulation.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 13:53:20 by prippa            #+#    #+#             */
/*   Updated: 2019/03/02 13:53:21 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRON_MANIPULATION_H
# define ENVIRON_MANIPULATION_H

# include "libft.h"
# include "ft_list.h"

typedef struct	s_env
{
	char		*key;
	char		*value;
}				t_env;

# define ENV(k, v) &(t_env){.key = k, .value = v}

void			env_del_body(t_env *e);
void			env_del_list(void *content, size_t content_size);

t_list_elem		*env_get_obj_by_key(t_list_elem *start, const char *key);
char			*env_get_vlu_by_key(t_list_elem *start, const char *key);
void			env_set(t_list *env_list,
					const t_env *new_env, t_bool overwrite);
int32_t			env_unset(t_list *env_list, const char *key);
void			env_print(t_list *env_lst);
char			**env_convert_to_arr(t_list_elem *start, size_t list_size);
t_env			env_make_clone_of_body(const t_env *origin);
void			env_make_clone(t_list *dst, t_list_elem *src_start);

void			env_check_global_event(const t_env *e);
void			env_new_path(const char *paths_str);

#endif
