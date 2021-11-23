/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:13:41 by mbarra            #+#    #+#             */
/*   Updated: 2021/11/23 20:16:19 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = ft_strlen(str);
	while (*str)
		write(1, str++, 1);
	return (i);
}

int	ft_s(char *str)
{
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	else
	{
		ft_putstr(str);
		return (ft_strlen(str));
	}
}

int	ft_c(char c)
{
	ft_putchar((unsigned char)c);
	return (1);
}

void	ft_putnbr(int i)
{
	if (i == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (i < 0)
	{
		ft_putchar('-');
		i *= -1;
	}
	if (i > 9)
		ft_putnbr(i / 10);
	ft_putchar(i % 10 + '0');
}

void	ft_putnbr_u(unsigned int i)
{
	if (i > 9)
		ft_putnbr(i / 10);
	ft_putchar(i % 10 + '0');
}
