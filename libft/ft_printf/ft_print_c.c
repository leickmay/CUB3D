/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 10:45:42 by leickmay          #+#    #+#             */
/*   Updated: 2020/12/19 15:18:48 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_c_width(int width, t_flags *flag, va_list ap)
{
	int		count;
	char	c;

	count = 0;
	c = (char)va_arg(ap, int);
	if (flag->minus == 0)
	{
		while (count < width - 1)
		{
			ft_putchar(' ');
			count++;
		}
	}
	ft_putchar(c);
	count++;
	if (flag->minus == 1)
	{
		while (count < width)
		{
			ft_putchar(' ');
			count++;
		}
	}
	return (count);
}

int		ft_print_c(t_flags *flag, va_list ap)
{
	int	count;
	int	width;

	if (flag->star == 1)
		width = va_arg(ap, int);
	else
		width = flag->width;
	if (width < 0)
	{
		width *= -1;
		flag->minus = 1;
	}
	count = ft_print_c_width(width, flag, ap);
	return (count);
}
