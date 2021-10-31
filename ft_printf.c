/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:33:18 by mbarra            #+#    #+#             */
/*   Updated: 2021/10/31 14:02:32 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_type(va_list ap, char c)
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
	int		len;
	va_list	ap;

	va_start(ap, format);
	done = 0;
	len = 0;
	while (format[done] != '\0')
	{
		if (format[done] == '%')
		{
			if (format[done + 1] == '\0')
				break ;
			len += ft_type(ap, format[done + 1]);
			done++;
		}
		else
		{
			write(1, &format[done], 1);
			len++;
		}
		done++;
	}
	va_end(ap);
	return (len);
}
