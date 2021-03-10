/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:56:04 by leickmay          #+#    #+#             */
/*   Updated: 2021/01/09 13:57:02 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char		*ft_strdup_gnl(const char *s1)
{
	size_t	i;
	size_t	j;
	char	*s2;

	i = ft_strlen_gnl(s1);
	if (!(s2 = malloc(sizeof(const char) * (i + 1))))
		return (0);
	j = 0;
	while (j < i)
	{
		s2[j] = s1[j];
		j++;
	}
	s2[j] = '\0';
	return (s2);
}

char		*copy_join_gnl(char *s1, char *s2)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*new;

	len = ft_strlen_gnl(s1) + ft_strlen_gnl(s2);
	if (!(new = malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	return (new);
}

char		*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*new;
	int		no_free;

	if (!s2 && !s1)
		return (0);
	no_free = 0;
	if (!s1)
	{
		s1 = "";
		no_free = 1;
	}
	new = copy_join_gnl(s1, s2);
	if (no_free == 0)
		free(s1);
	return (new);
}

char		*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char			*s2;
	unsigned int	i;

	if (!s)
		return (0);
	if (start >= ft_strlen_gnl(s))
		start = ft_strlen_gnl(s);
	if (!(s2 = malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (i < len && s[i + start])
	{
		s2[i] = s[i + start];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
