/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbruns_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 10:44:38 by mbarra            #+#    #+#             */
/*   Updated: 2021/10/26 11:54:37 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbruns_fd(unsigned int n, int fd)
{
	if (n >= 10)
		ft_putnbruns_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
	return ;
}
