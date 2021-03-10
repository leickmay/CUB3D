/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 10:07:49 by leickmay          #+#    #+#             */
/*   Updated: 2020/12/21 17:43:57 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_d(t_flags *flag, va_list ap)
{
	int		count;
	int		width;
	int		dot;
	char	*nb;

	width = ft_find_width(flag, ap);
	dot = ft_find_dot(flag, ap);
	if (!(nb = ft_itoa(va_arg(ap, int))))
		return (-1);
	if (dot > -1)
		count = ft_print_d_dot(width, dot, nb, flag);
	else if (dot <= -1 && flag->zeros == 1 && flag->minus == 0)
		count = ft_print_d_zeros(width, nb, flag);
	else
		count = ft_print_d_width(width, nb, flag);
	free(nb);
	return (count);
}

int		ft_print_d_width(int width, char *nb, t_flags *flag)
{
	int		count;

	count = 0;
	if (nb != NULL)
		count = ft_strlen(nb);
	if (flag->minus == 0)
	{
		while (count < width)
		{
			ft_putchar(' ');
			count++;
		}
	}
	if (nb != NULL)
		ft_putstr(nb);
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
