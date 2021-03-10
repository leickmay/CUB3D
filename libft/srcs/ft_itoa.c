/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:41:17 by leickmay          #+#    #+#             */
/*   Updated: 2021/01/09 11:43:41 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		ft_int_length(int nb)
{
	int		len;
	long	a;

	len = 1;
	a = nb;
	if (a < 0)
	{
		a *= -1;
		len++;
	}
	while (a >= 10)
	{
		a = a / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int nb)
{
	char	*str;
	int		len;
	long	a;

	len = ft_int_length(nb);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	a = nb;
	if (a < 0)
		a *= -1;
	str[len] = '\0';
	while (a >= 10)
	{
		str[len - 1] = a % 10 + '0';
		a = a / 10;
		len--;
	}
	str[len - 1] = a % 10 + '0';
	if (nb < 0)
		str[len - 2] = '-';
	return (str);
}
