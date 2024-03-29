/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_def.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:20:56 by prippa            #+#    #+#             */
/*   Updated: 2019/02/11 12:20:57 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEF_H
# define FT_DEF_H

# include <stdint.h>
# include <fcntl.h>

# define ERR			-1
# define OK				0
# define MALLOC_ERR		"malloc() failed"
# define OPEN_ERR		"open() failed"
# define READ_ERR		"read() failed"
# define WRITE_ERR		"write() failed"

# define OPEN_REWRITE_FLAGS		(O_CREAT | O_WRONLY | O_TRUNC)
# define OPEN_APPEND_FLAGS		(O_CREAT | O_WRONLY | O_APPEND)
# define OPEN_RDWR_APPEND_FLAGS	(O_CREAT | O_RDWR | O_APPEND)
# define OPEN_CREATE_RW_RIGHTS	(S_IWUSR | S_IRUSR)

# define EMPTY_STR		""
# define ENDL			'\n'

typedef char	t_bool;
enum			{ false, true };

typedef struct	s_point
{
	int32_t		x;
	int32_t		y;
}				t_point;

typedef void	(*t_fatal_exit_func)(const char *message);
extern t_fatal_exit_func g_fef;

# define ABS(x) (((x) < 0) ? -(x) : (x))

# define MAX(a, b) ((a) > (b) ? (a) : (b))
# define MIN(a, b) ((a) < (b) ? (a) : (b))

# define SWITCH_LOGIC(x) ((x) ? false : true)

/*
************************************ Colors **********************************
*/

# define BOLD			"\e[1m"
# define DIM			"\e[2m"
# define ITALIC			"\e[3m"
# define UNDER_LINE		"\e[4m"
# define BACK			"\e[7m"

# define RED			"\x1B[31m"
# define YELLOW 		"\x1B[33m"
# define GREEN			"\x1B[32m"
# define CYAN			"\x1B[36m"
# define BLUE			"\x1B[34m"
# define MAGENTA		"\x1B[35m"
# define GRAY			"\e[90m"
# define WHITE			"\x1B[37m"
# define COLOR_RESET	"\x1B[0m"

# define F_NONE -1

typedef enum	e_color_type
{
	CT_BOLD,
	CT_DIM,
	CT_ITALIC,
	CT_UNDER,
	CT_BACK,
	CT_SIZE
}				t_color_type;

typedef enum	e_color
{
	C_RED,
	C_YELLOW,
	C_GREEN,
	C_CYAN,
	C_BLUE,
	C_MAGENTA,
	C_GREY,
	C_WHITE,
	C_SIZE
}				t_color;

#endif
