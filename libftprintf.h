/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:26:24 by mbarra            #+#    #+#             */
/*   Updated: 2021/10/21 18:15:04 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIBFTPRINTF_H__
# define __LIBFTPRINTF_H__

# include <stdio.h> //printf
# include <stdlib.h> //malloc
# include <stdarg.h> // va_arg(), va_start(), va_copy() и va_end()
# include "libft.h"

typedef struct	s_type
{
	int				type;
	unsigned int	width;
	unsigned int	precision;
	int				minus;
}				t_type;


// void va_start(va_list ap, last);
// type va_arg(va_list ap, type);
// void va_end(va_list ap);
// void va_copy(va_list dest, va_list src);


int		printf(const char *format, ...);

#endif
