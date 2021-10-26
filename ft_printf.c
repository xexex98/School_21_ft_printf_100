/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:33:18 by mbarra            #+#    #+#             */
/*   Updated: 2021/10/26 12:34:08 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(va_list ap, char c)
{
	int	size;

	size = 0;
	if (c == 'c')
		size += ft_print_c(va_arg(ap, int));
	else if (c == 's')
		size += ft_print_s(va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		size += ft_print_id(va_arg(ap, int));
	else if (c == 'u')
		size += ft_print_ud(va_arg(ap, unsigned int));
	else if (c == 'p')
		size += ft_print_p((unsigned long)va_arg(ap, void *));
	else if (c == 'x')
		size += ft_print_x(va_arg(ap, unsigned int));
	else if (c == 'X')
		size += ft_print_ux(va_arg(ap, unsigned int));
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		size += 1;
	}
	return (size);
}

int	ft_printf(const char	*format, ...)
{
	int		done;

	va_list	ap;
	va_start(ap, format);
	done = 0;
	while (format[done] != '\0')
	{
		if (format[done] == '%')
		{
			done += ft_type(ap, format[done + 1]);
		}
		else
			write(1, &format[done], 1);
		done++;
	}
	va_end(ap);
	printf("d:  %i\n", done);
	return (done);
}

// int main(void)
// {
// 	// char *d = "-12345654";
// 	// ft_printf("12345 %p", d);
// 	// write(1, "\n", 1);
// 	// printf("12345 %p", d);
// 	// write(1, "\n", 1);
// 	ft_printf("ft: %i\n %d\n", ft_intlen(0), ft_strlen("-123"));
// 	printf("printf: %zu\n %zu\n ", ft_intlen(-0), ft_strlen("-123"));
// 	return (0);
// }