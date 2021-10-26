/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:26:24 by mbarra            #+#    #+#             */
/*   Updated: 2021/10/26 12:25:43 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

size_t	ft_hexlen(unsigned int n);
size_t	ft_intlen(long long int n);
int		ft_print_c(int	c);
int		ft_print_id(int n);
int		ft_print_p(unsigned int n);
int		ft_print_s(char *s);
int		ft_print_ud(unsigned int n);
int		ft_print_ux(unsigned int n);
int		ft_print_x(unsigned int n);
int		ft_printf(const char	*format, ...);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbruns_fd(unsigned int n, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
// int		ft_type(va_list ap, char c);

#endif
