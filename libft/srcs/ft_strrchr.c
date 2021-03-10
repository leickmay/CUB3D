/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 17:44:52 by leickmay          #+#    #+#             */
/*   Updated: 2021/01/09 10:47:51 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*ptr;
	size_t			i;

	i = 0;
	ptr = 0;
	while (((char *)s)[i] != 0)
	{
		if (((char *)s)[i] == c)
			ptr = &((char *)s)[i];
		i++;
	}
	if (c == '\0')
		return (&((char *)s)[i]);
	return (ptr);
}
