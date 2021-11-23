/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:18:13 by mbarra            #+#    #+#             */
/*   Updated: 2021/11/23 20:18:14 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_strlen(char *str);
int		ft_intlen(long long int n);
int		ft_hexlen(long int n);
int		ft_hexlenp(unsigned long int n);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_s(char *str);
int		ft_c(char c);
void	ft_putnbr(int i);
void	ft_putnbr_u(unsigned int i);
int		ft_i_d(int i);
int		ft_u(unsigned int i);
void	ft_putnbr_x(unsigned long int n);
void	ft_putnbr_ux(unsigned long int n);
int		ft_x(unsigned long int n);
int		ft_ux(unsigned long int n);
int		ft_p(unsigned long i);
int		ft_format(va_list ap, char c);
int		ft_printf(const char *format, ...);

#endif
