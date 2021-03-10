/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:29:23 by leickmay          #+#    #+#             */
/*   Updated: 2021/01/09 10:47:23 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	nb_letters(char const *s, char c)
{
	size_t i;

	i = 0;
	while (*s)
	{
		if (*s == c)
			return (i);
		i++;
		s++;
	}
	return (i);
}

static size_t	nb_words(char const *s, char c)
{
	size_t i;
	size_t letters;

	i = 0;
	while (*s)
	{
		letters = nb_letters(s, c);
		if (letters != 0)
			i++;
		else
			s++;
		s += letters;
	}
	return (i);
}

static char		*copy_str(char const *s, size_t letters)
{
	size_t	j;
	char	*tab;

	j = 0;
	if (!(tab = malloc(sizeof(char) * (letters + 1))))
		return (0);
	while (j < letters)
	{
		tab[j] = s[j];
		j++;
	}
	tab[j] = '\0';
	return (tab);
}

static char		*free_tabs(const char *s, size_t letters, size_t i, char **tab)
{
	if (!(tab[i] = copy_str(s, letters)))
	{
		while (i >= 0)
		{
			free(tab[i]);
			i--;
		}
		free(tab);
		return (0);
	}
	return (tab[i]);
}

char			**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	letters;

	if (!s)
		return (0);
	i = 0;
	if (!(tab = malloc(sizeof(char *) * (nb_words(s, c) + 1))))
		return (0);
	while (*s)
	{
		letters = nb_letters(s, c);
		if (letters != 0)
		{
			tab[i] = free_tabs(s, letters, i, tab);
			i++;
		}
		if (letters == 0)
			s++;
		s += letters;
	}
	tab[i] = 0;
	return (tab);
}
