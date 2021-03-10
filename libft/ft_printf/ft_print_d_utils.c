/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 13:52:36 by leickmay          #+#    #+#             */
/*   Updated: 2020/12/23 12:10:17 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*fill_zeros(int width, int count, char *new_nb)
{
	int i;

	i = 0;
	while (count < width)
	{
		new_nb[i] = '0';
		i++;
		count++;
	}
	new_nb[i] = '\0';
	return (new_nb);
}

int		ft_print_d_dot_more(int width, int dot, char *nb, t_flags *flag)
{
	int		count;
	char	*new_nb;

	count = ft_strlen(nb);
	if (!(new_nb = malloc(sizeof(char) * (dot + 1))))
		return (-1);
	new_nb = fill_zeros(dot, count, new_nb);
	count = dot;
	if (nb[0] == '-')
	{
		if (!(new_nb = ft_strjoin_minus(new_nb, nb)))
			return (-1);
	}
	else
	{
		if (!(new_nb = ft_strjoin_free(new_nb, nb)))
			return (-1);
	}
	count = ft_print_d_width(width, new_nb, flag);
	free(new_nb);
	return (count);
}

int		ft_print_d_dot(int width, int dot, char *nb, t_flags *flag)
{
	int count;

	count = ft_strlen(nb);
	if (nb[0] == '-')
		dot++;
	if (dot == 0 && nb[0] == '0' && count == 1)
		count = ft_print_d_width(width, NULL, flag);
	else if (dot <= count)
		count = ft_print_d_width(width, nb, flag);
	else
	{
		if ((count = ft_print_d_dot_more(width, dot, nb, flag)) == -1)
			return (-1);
	}
	return (count);
}

int		ft_print_d_zeros_more(int width, char *nb, t_flags *flag)
{
	int		count;
	char	*new_nb;

	count = ft_strlen(nb);
	if (!(new_nb = malloc(sizeof(char) * (width + 1))))
		return (-1);
	new_nb = fill_zeros(width, count, new_nb);
	count = width;
	if (nb[0] == '-')
	{
		if (!(new_nb = ft_strjoin_minus(new_nb, nb)))
			return (-1);
	}
	else
	{
		if (!(new_nb = ft_strjoin_free(new_nb, nb)))
			return (-1);
	}
	count = ft_print_d_width(width, new_nb, flag);
	free(new_nb);
	return (count);
}

int		ft_print_d_zeros(int width, char *nb, t_flags *flag)
{
	int		count;

	count = ft_strlen(nb);
	if (width <= count)
		count = ft_print_d_width(width, nb, flag);
	else
	{
		if ((count = ft_print_d_zeros_more(width, nb, flag)) == -1)
			return (-1);
	}
	return (count);
}
