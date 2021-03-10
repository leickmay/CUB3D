/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 08:44:36 by leickmay          #+#    #+#             */
/*   Updated: 2021/01/09 12:02:32 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_p_width(int width, char *nb, t_flags *flag)
{
	int		count;

	count = ft_strlen(nb) + 2;
	if (flag->minus == 0)
	{
		while (count < width)
		{
			ft_putchar(' ');
			count++;
		}
	}
	ft_putstr("0x");
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

int		ft_print_p_dot(int width, int dot, char *nb, t_flags *flag)
{
	int		count;
	int		i;
	char	*new_nb;

	count = ft_strlen(nb);
	i = 0;
	if (dot <= count)
		count = ft_print_p_width(width, nb, flag);
	if (dot > count)
	{
		if (!(new_nb = malloc(sizeof(char) * (dot + 1))))
			return (-1);
		while (count < dot)
		{
			new_nb[i] = '0';
			i++;
			dot--;
		}
		new_nb[i] = '\0';
		if (!(new_nb = ft_strjoin_free(new_nb, nb)))
			return (-1);
		count = ft_print_p_width(width, new_nb, flag);
		free(new_nb);
	}
	return (count);
}

int		ft_print_p(t_flags *flag, va_list ap)
{
	int		count;
	int		width;
	int		dot;
	char	*nb;

	width = ft_find_width(flag, ap);
	dot = ft_find_dot(flag, ap);
	if (!(nb = \
	ft_itoa_base_seize((size_t)(va_arg(ap, void *)), "0123456789abcdef")))
		return (-1);
	if (flag->dot == -1 && (flag->zeros == 0
	|| (flag->zeros == 1 && flag->minus == 1)))
		count = ft_print_p_width(width, nb, flag);
	if (flag->dot > -1)
		count = ft_print_p_dot(width, dot, nb, flag);
	if (flag->zeros == 1 && flag->minus == 0 && flag->dot == -1)
		count = ft_print_p_dot(0, width, nb, flag);
	free(nb);
	return (count);
}
