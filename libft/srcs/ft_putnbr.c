/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 11:17:29 by leickmay          #+#    #+#             */
/*   Updated: 2021/01/09 12:01:27 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr(int n)
{
	long	a;

	a = n;
	if (n < 0)
	{
		a *= -1;
		ft_putchar('-');
	}
	if (a >= 10)
		ft_putnbr(a / 10);
	ft_putchar(a % 10 + '0');
}
