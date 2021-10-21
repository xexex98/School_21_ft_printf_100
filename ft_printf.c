/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:33:18 by mbarra            #+#    #+#             */
/*   Updated: 2021/10/21 18:08:28 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// va_list
// void va_start(va_list ap, last);
// type va_arg(va_list ap, type);
// void va_end(va_list ap);
// void va_copy(va_list dest, va_list src);

void	ft_printf(const char	*format, ...)
{
	unsigned int	length;

	length = 0;
	va_start(args, format)
	while (*format)
	{
		if (*format != '%' && *format)
			write(1, format, 1);
		else
			return ;
		format++;
	}
	va_end (args);
}
 
int main(void)
{
	ft_printf("123  %d");
	return 0;
}
