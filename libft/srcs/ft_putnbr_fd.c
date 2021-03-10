/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:45:08 by leickmay          #+#    #+#             */
/*   Updated: 2021/01/09 10:47:18 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long a;

	a = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		a = -1 * a;
	}
	if (a >= 10)
	{
		ft_putnbr_fd((a / 10), fd);
	}
	ft_putchar_fd((a % 10 + '0'), fd);
}
