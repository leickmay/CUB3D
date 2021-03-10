/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 14:00:17 by leickmay          #+#    #+#             */
/*   Updated: 2020/12/21 17:10:13 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		is_in_flags(char c)
{
	if (c == '-' || c == '0' || c == '.' || c == '*'
	|| ft_isdigit(c) == 1 || c == ' ')
		return (1);
	return (0);
}

int		parse_flags(char *str, int i, t_flags *flag)
{
	i++;
	while (is_in_flags(str[i]))
	{
		if (str[i] == '0')
			if (str[i - 1] == '%' || str[i - 1] == ' ')
				flag->zeros = 1;
		if (ft_isdigit(str[i]))
			if ((i = get_digit(str, i, flag)) == -1)
				return (-1);
		if (str[i] == '.')
			if ((i = get_dot(str, i, flag)) == -1)
				return (-1);
		if (str[i] == '-')
			flag->minus = 1;
		if (str[i] == '*')
			get_star(str, i, flag);
		i++;
	}
	return (i);
}

int		set_type(char *str, int i, t_flags *flag)
{
	if (str[i] == 'c')
		flag->type = 'c';
	if (str[i] == 's')
		flag->type = 's';
	if (str[i] == 'p')
		flag->type = 'p';
	if (str[i] == 'd')
		flag->type = 'd';
	if (str[i] == 'i')
		flag->type = 'i';
	if (str[i] == 'u')
		flag->type = 'u';
	if (str[i] == 'x')
		flag->type = 'x';
	if (str[i] == 'X')
		flag->type = 'X';
	if (str[i] == '%')
		flag->type = '%';
	if (flag->type == 0)
		return (-1);
	return (1);
}
