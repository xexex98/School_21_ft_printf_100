/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:33:18 by mbarra            #+#    #+#             */
/*   Updated: 2021/10/24 19:00:56 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_type(va_list ap, char c)
{
	int	size;
	size = 0;
	if (c == 'c')
		size += ft_char_c(va_arg(ap, int));
	else if (c == 's')
		size += ft_string_s(va_arg(ap, char *));
	return (size);
}
int	foo(char	*format, ...)
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
			done++;
		}
		else
		{
			write(1, &format[done], 1) ;
		}
		done++;
	}
	va_end(ap);
	printf("%i\n", done);
	return (done);
}

int main(void)
{
	char *d;
	foo("123%s", "69");
	return (0);
}