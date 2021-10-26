/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 10:45:05 by mbarra            #+#    #+#             */
/*   Updated: 2021/10/26 12:32:05 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(char *s)
{
	if (s != NULL)
	{
		ft_putstr_fd(s, 1);
		return (ft_strlen(s));
	}
	else
	{
		ft_putstr_fd("null", 2);
		return (ft_strlen("null"));
	}
}
