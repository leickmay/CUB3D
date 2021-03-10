/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 08:32:59 by leickmay          #+#    #+#             */
/*   Updated: 2020/12/23 12:02:37 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flags		flags_init(t_flags flag)
{
	flag.dot = -1;
	flag.minus = 0;
	flag.star = 0;
	flag.zeros = 0;
	flag.width = 0;
	flag.type = 0;
	return (flag);
}

int			ft_print_conversion(t_flags *flag, va_list ap)
{
	int count;

	count = 0;
	if (flag->type == 'c')
		count = ft_print_c(flag, ap);
	if (flag->type == 's')
		count = ft_print_s(flag, ap);
	if (flag->type == 'p')
		count = ft_print_p(flag, ap);
	if (flag->type == 'd' || flag->type == 'i')
		count += ft_print_d(flag, ap);
	if (flag->type == 'u')
		count += ft_print_u(flag, ap);
	if (flag->type == 'x')
		count += ft_print_x(flag, ap);
	if (flag->type == 'X')
		count += ft_print_big_x(flag, ap);
	if (flag->type == '%')
		count += ft_print_percent(flag, ap);
	return (count);
}

int			set_flags_type(int i, char *str, t_flags *flag)
{
	if ((i = parse_flags(str, i, flag)) == -1)
		return (-1);
	if (set_type(str, i, flag) == 1)
		i++;
	return (i);
}

int			treat_str(char *str, va_list ap)
{
	int		i;
	int		j;
	int		count;
	t_flags	flag;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar(str[i++]);
			count++;
		}
		while (str[i] == '%')
		{
			flag = flags_init(flag);
			if ((i = set_flags_type(i, str, &flag)) == -1)
				return (-1);
			if ((j = ft_print_conversion(&flag, ap)) == -1)
				return (-1);
			count += j;
		}
	}
	return (count);
}

int			ft_printf(const char *format, ...)
{
	char	*copy;
	int		length;
	va_list	ap;

	if (!(copy = ft_strdup(format)))
		return (-1);
	va_start(ap, format);
	length = treat_str(copy, ap);
	va_end(ap);
	free(copy);
	return (length);
}
