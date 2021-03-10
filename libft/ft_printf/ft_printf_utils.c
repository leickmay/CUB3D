/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 14:40:02 by leickmay          #+#    #+#             */
/*   Updated: 2021/01/09 13:38:21 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_find_width(t_flags *flag, va_list ap)
{
	int width;

	if (flag->star == 0 || flag->star == 2)
		width = flag->width;
	if (flag->star == 1 || flag->star == 3)
	{
		width = va_arg(ap, int);
		if (width < 0)
		{
			flag->minus = 1;
			width *= -1;
		}
	}
	return (width);
}

int		ft_find_dot(t_flags *flag, va_list ap)
{
	int dot;

	if (flag->star == 0 || flag->star == 1)
		dot = flag->dot;
	if (flag->star == 2 || flag->star == 3)
		dot = va_arg(ap, int);
	return (dot);
}

char	*ft_strjoin_minus(char *new_nb, char *nb)
{
	char *nb_joined;

	nb[0] = '0';
	new_nb[0] = '-';
	nb_joined = ft_strjoin(new_nb, nb);
	free(new_nb);
	return (nb_joined);
}
