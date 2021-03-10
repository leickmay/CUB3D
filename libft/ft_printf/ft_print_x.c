/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 15:59:48 by leickmay          #+#    #+#             */
/*   Updated: 2021/01/09 11:53:16 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_x(t_flags *flag, va_list ap)
{
	int		count;
	int		width;
	int		dot;
	char	*nb;

	width = ft_find_width(flag, ap);
	dot = ft_find_dot(flag, ap);
	if (!(nb = \
	ft_itoa_base_seize((size_t)va_arg(ap, unsigned int), "0123456789abcdef")))
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

int		ft_print_big_x(t_flags *flag, va_list ap)
{
	int		count;
	int		width;
	int		dot;
	char	*nb;

	width = ft_find_width(flag, ap);
	dot = ft_find_dot(flag, ap);
	if (!(nb = \
	ft_itoa_base_seize((size_t)va_arg(ap, unsigned int), "0123456789ABCDEF")))
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
