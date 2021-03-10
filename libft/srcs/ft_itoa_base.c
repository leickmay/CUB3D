/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 11:45:18 by leickmay          #+#    #+#             */
/*   Updated: 2021/01/09 11:53:41 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		ft_int_length(int nb, char *base)
{
	int		len;
	int		base_len;
	long	a;

	base_len = ft_strlen(base);
	len = 1;
	a = nb;
	if (a < 0)
	{
		a *= -1;
		len++;
	}
	while (a >= base_len)
	{
		a = a / base_len;
		len++;
	}
	return (len);
}

char			*ft_itoa_base(int nb, char *base)
{
	char	*str;
	int		len;
	int		base_len;
	long	a;

	base_len = ft_strlen(base);
	len = ft_int_length(nb, base);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	a = nb;
	if (a < 0)
		a *= -1;
	str[len] = '\0';
	while (a >= base_len)
	{
		str[len - 1] = base[a % base_len];
		a = a / base_len;
		len--;
	}
	str[len - 1] = base[a % base_len];
	if (nb < 0)
		str[len - 2] = '-';
	return (str);
}
