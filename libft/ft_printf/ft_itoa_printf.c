/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 14:46:20 by leickmay          #+#    #+#             */
/*   Updated: 2021/01/09 11:52:22 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_int_length(size_t nb, size_t base)
{
	int len;

	len = 1;
	while (nb >= base)
	{
		nb = nb / base;
		len++;
	}
	return (len);
}

char			*ft_itoa_unsigned_int(unsigned int nb)
{
	char	*str;
	int		len;

	len = ft_int_length(nb, 10);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (nb >= 10)
	{
		str[len - 1] = nb % 10 + '0';
		nb = nb / 10;
		len--;
	}
	str[0] = nb + '0';
	return (str);
}

char			*ft_itoa_base_seize(size_t nb, char *base)
{
	char	*str;
	int		len;

	len = ft_int_length(nb, 16);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (nb >= 16)
	{
		str[len - 1] = base[nb % 16];
		nb = nb / 16;
		len--;
	}
	str[len - 1] = base[nb];
	return (str);
}
