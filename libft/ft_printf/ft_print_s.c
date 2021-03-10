/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 12:12:16 by leickmay          #+#    #+#             */
/*   Updated: 2020/12/21 16:06:59 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_s_width(int width, char *str, t_flags *flag)
{
	int	count;
	int	len;

	count = 0;
	len = ft_strlen(str);
	if (flag->minus == 0)
	{
		while (count < width - len)
		{
			ft_putchar(' ');
			count++;
		}
	}
	ft_putstr(str);
	count += len;
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

int		ft_print_s_dot(int width, int dot, char *str, t_flags *flag)
{
	int		count;
	char	*new_str;

	if (dot >= (int)ft_strlen(str))
		count = ft_print_s_width(width, str, flag);
	if (dot < (int)ft_strlen(str))
	{
		if (!(new_str = ft_substr(str, 0, dot)))
			return (-1);
		count = ft_print_s_width(width, new_str, flag);
		free(new_str);
	}
	return (count);
}

int		ft_find_dot_s(t_flags *flag, va_list ap)
{
	int dot;

	if (flag->star == 0 || flag->star == 1)
		dot = flag->dot;
	if (flag->star == 2 || flag->star == 3)
		dot = va_arg(ap, int);
	if (dot < -1)
		dot = -1;
	return (dot);
}

int		ft_print_s(t_flags *flag, va_list ap)
{
	int		count;
	int		width;
	int		dot;
	char	*str;

	width = ft_find_width(flag, ap);
	dot = ft_find_dot_s(flag, ap);
	str = va_arg(ap, char*);
	if (str == NULL)
		str = "(null)";
	if (flag->dot == -1)
		count = ft_print_s_width(width, str, flag);
	if (flag->dot > -1)
		count = ft_print_s_dot(width, dot, str, flag);
	return (count);
}
