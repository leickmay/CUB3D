/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:22:20 by leickmay          #+#    #+#             */
/*   Updated: 2020/12/19 15:19:05 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_percent_width(int width, t_flags *flag, char c)
{
	int		count;

	count = 0;
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

int		ft_print_percent_zeros(int width, char c)
{
	int count;

	count = 0;
	while (count < width - 1)
	{
		ft_putchar('0');
		count++;
	}
	ft_putchar(c);
	count++;
	return (count);
}

int		ft_print_percent(t_flags *flag, va_list ap)
{
	int		count;
	int		width;
	char	c;

	c = '%';
	width = ft_find_width(flag, ap);
	if (flag->zeros == 0 || (flag->zeros == 1 && flag->minus == 1))
		count = ft_print_percent_width(width, flag, c);
	if (flag->zeros == 1 && flag->minus == 0)
		count = ft_print_percent_zeros(width, c);
	return (count);
}
