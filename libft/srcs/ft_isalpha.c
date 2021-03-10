/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 17:43:02 by leickmay          #+#    #+#             */
/*   Updated: 2021/01/09 10:46:15 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_isalpha(int c)
{
	int is_alpha;

	is_alpha = 1;
	if (c < 'A' || (c > 'Z' && c < 'a') || c > 'z')
		is_alpha = 0;
	return (is_alpha);
}
