/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:14:08 by mbarra            #+#    #+#             */
/*   Updated: 2021/11/23 20:17:54 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list ap, char c)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += ft_c(va_arg(ap, int));
	else if (c == 's')
		i += ft_s(va_arg(ap, char *));
	else if (c == 'i' || c == 'd')
		i += ft_i_d(va_arg(ap, int));
	else if (c == 'u')
		i += ft_u(va_arg(ap, unsigned int));
	else if (c == 'p')
		i += ft_p(va_arg(ap, unsigned long));
	else if (c == 'x')
		i += ft_x(va_arg(ap, unsigned int));
	else if (c == 'X')
		i += ft_ux(va_arg(ap, unsigned int));
	else if (c == '%')
		i += ft_putchar('%');
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	int		i;
	va_list	ap;

	i = 0;
	len = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				break ;
			len += ft_format(ap, format[i + 1]);
			i++;
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (len);
}

// #include <stdio.h>
// int	main(void)
// {
// 	printf("\n:or:%i", printf("%c\n", 'a'));
// 	printf("\n:my:%i", ft_printf("%c\n", 'a'));
// 	// printf("\n%i\n", ft_i_d(2147483649));
// 	return (0);
// }