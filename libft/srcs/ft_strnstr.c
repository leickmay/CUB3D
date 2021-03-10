/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 17:44:49 by leickmay          #+#    #+#             */
/*   Updated: 2021/01/09 10:47:48 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *hstck, const char *needle, size_t len)
{
	int			i;
	int			l;
	char		*str;
	char		*str2;

	i = 0;
	str = (char*)hstck;
	str2 = (char*)needle;
	if (needle[0] == '\0')
		return (str);
	l = ft_strlen(needle);
	while (str[i] && i <= (int)len - l)
	{
		if (ft_strncmp(&str[i], str2, l) == 0)
			return (&str[i]);
		i++;
	}
	return (0);
}
