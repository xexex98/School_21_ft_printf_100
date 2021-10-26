/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 10:50:38 by mbarra            #+#    #+#             */
/*   Updated: 2021/10/26 12:32:01 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(unsigned int n)
{
	char			*x = "123456789abcdef";
	size_t			i;
	size_t			len;
	char			*s;
	
	len = ft_hexlen(n);
	s = (char *)malloc(sizeof(len));
	if (!s)
		return (0);
	ft_putstr_fd("0x10", 1);
	s[len] = '\0';
	len--;
	while (n > 0)
	{
		i = n % 16;
		n = n / 16;
		if (i == 0)
			s[len--] = '0';
		else
			s[len--] = x[i - 1];
	}
	ft_putstr_fd(s, 1);
	free(s);
	return (ft_hexlen(n) + 4);
}
