/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 17:43:10 by leickmay          #+#    #+#             */
/*   Updated: 2021/01/09 10:46:22 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_isascii(int c)
{
	int is_ascii;

	is_ascii = 1;
	if (c < 0 || c > 127)
		is_ascii = 0;
	return (is_ascii);
}
