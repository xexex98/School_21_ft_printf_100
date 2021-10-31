/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 10:49:52 by mbarra            #+#    #+#             */
/*   Updated: 2021/10/31 14:02:44 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_ux(unsigned int n)
{
	size_t	i;
	size_t	len;
	char	*s;

	len = ft_hexlen(n);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (0);
	s[len] = '\0';
	len--;
	if (n == 0)
		s[len] = '0';
	while (n != 0)
	{
		i = n % 16;
		n = n / 16;
		if (i >= 0 && i <= 9)
			s[len--] = i + 48;
		else
			s[len--] = i + 55;
	}
	ft_putstr_fd(s, 1);
	free(s);
	return (ft_strlen(s));
}
