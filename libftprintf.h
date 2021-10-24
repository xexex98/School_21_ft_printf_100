/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:26:24 by mbarra            #+#    #+#             */
/*   Updated: 2021/10/24 19:02:29 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIBFTPRINTF_H__
# define __LIBFTPRINTF_H__

# include <stdio.h> //printf
# include <stdlib.h> //malloc
# include <stdarg.h> // va_arg(), va_start(), va_copy() и va_end()
# include "libft.h"

int	ft_char_c(int	c);
int	ft_type(va_list(ap), char c);
int ft_string_s(char *s);
void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);

#endif
