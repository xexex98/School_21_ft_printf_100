/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:33:18 by mbarra            #+#    #+#             */
/*   Updated: 2021/10/25 19:25:46 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	num = (unsigned int) n;
	if (num >= 10)
		ft_putnbr_fd(num / 10, fd);
	ft_putchar_fd(num % 10 + '0', fd);
	return ;
}

void	ft_putnbruns_fd(unsigned int n, int fd)
{
	if (n >= 10)
		ft_putnbruns_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
	return ;
}

int ft_string_s(char *s)
{

	if (s != NULL)
	{
		ft_putstr_fd(s, 1);
		return (ft_strlen(s));
	}
	else
		return (ft_strlen("null"));
}

int	ft_char_c(int c)
{
	ft_putchar_fd((unsigned char)c, 1);
	return (1);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

size_t	ft_strlen(const char	*str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s != '\0')
		write(fd, s++, 1);
}

static int ft_integer_i(int n)
{
	ft_putnbr_fd(n, 1);
	return (1);
}

static int ft_unsigneddec(unsigned int n)
{
	ft_putnbruns_fd(n, 1);
	return (1);
}

static size_t	ft_hexlen(unsigned int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

int ft_hexx(unsigned int n)
{
	char *x = "123456789abcdef";
	unsigned int i;
	int len;
	char *s;

	len = ft_hexlen(n);
	s = (char *)malloc(sizeof(len));
	if (!s)
		return 0;
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
	return (ft_hexlen(n));
}

int ft_hexX(unsigned int n)
{
	char *x = "123456789ABCDEF";
	unsigned int i;
	int len;
	char *s;

	len = ft_hexlen(n);
	s = (char *)malloc(sizeof(len));
	if (!s)
		return 0;
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
	return (ft_hexlen(n));
}

int ft_pointer_p(unsigned int n)
{
	char *x = "123456789abcdef";
	unsigned int i;
	int len;
	char *s;

	len = ft_hexlen(n);
	s = (char *)malloc(sizeof(len));
	if (!s)
		return 0;
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
	return (ft_hexlen(n));
}

int	ft_type(va_list ap, char c)
{
	int	size;
	size = 0;
	if (c == 'c')
		size += ft_char_c(va_arg(ap, int));
	else if (c == 's')
		size += ft_string_s(va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		size += ft_integer_i(va_arg(ap, int));
	else if (c == 'u')
		size += ft_unsigneddec(va_arg(ap, unsigned int));
	else if (c == 'p')
		size += ft_pointer_p((unsigned long)va_arg(ap, void *));
	else if (c == 'x')
		size += ft_hexx(va_arg(ap, unsigned int)); 
	else if (c == 'X')
		size += ft_hexX(va_arg(ap, unsigned int));
	else if (c == '%')
		ft_putchar_fd('%', 1);
	return (size);
}

int	ft_printf(char	*format, ...)
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
	// printf("%i\n", done);
	return (done);
}

int main(void)
{
	char *d = "asd";
	ft_printf("12345 %s%", d);
	write(1, "\n", 1);
	printf("12345 %s", d);
	write(1, "\n", 1);
	return (0);
}