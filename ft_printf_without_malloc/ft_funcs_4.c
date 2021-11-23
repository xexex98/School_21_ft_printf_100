/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:14:28 by mbarra            #+#    #+#             */
/*   Updated: 2021/11/23 20:17:02 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ux(unsigned long int n)
{
	ft_putnbr_ux(n);
	return (ft_hexlen(n));
}

int	ft_p(unsigned long i)
{
	ft_putstr("0x");
	ft_putnbr_x(i);
	return (ft_hexlenp(i) + 2);
}
