/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:14:01 by mbarra            #+#    #+#             */
/*   Updated: 2021/11/23 20:16:52 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_i_d(int i)
{
	ft_putnbr(i);
	return (ft_intlen(i));
}

int	ft_u(unsigned int i)
{
	ft_putnbr_u(i);
	return (ft_intlen(i));
}

void	ft_putnbr_x(unsigned long int n)
{
	if (n >= 16)
	{
		ft_putnbr_x(n / 16);
		ft_putnbr_x(n % 16);
	}
	else if (n >= 10 && n <= 16)
		ft_putchar(n + 87);
	else
		ft_putchar(n + '0');
}

void	ft_putnbr_ux(unsigned long int n)
{
	if (n >= 16)
	{
		ft_putnbr_ux(n / 16);
		ft_putnbr_ux(n % 16);
	}
	else if (n >= 10 && n <= 16)
		ft_putchar(n + 55);
	else
		ft_putchar(n + '0');
}

int	ft_x(unsigned long int n)
{
	ft_putnbr_x(n);
	return (ft_hexlen(n));
}
