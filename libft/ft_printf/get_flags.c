/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:47:50 by leickmay          #+#    #+#             */
/*   Updated: 2021/01/09 11:12:06 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			get_digit(char *str, int i, t_flags *flag)
{
	int		a;
	char	*s;

	a = i;
	while (ft_isdigit(str[a]) == 1)
		a++;
	if (!(s = ft_substr(str, i, a - i)))
		return (-1);
	flag->width = ft_atoi(s);
	free(s);
	i = a - 1;
	return (i);
}

int			get_dot(char *str, int i, t_flags *flag)
{
	int		a;
	char	*s;

	i++;
	a = i;
	while (ft_isdigit(str[a]) == 1)
		a++;
	if (!(s = ft_substr(str, i, a - i)))
		return (-1);
	flag->dot = ft_atoi(s);
	free(s);
	i = a - 1;
	return (i);
}

void		get_star(char *str, int i, t_flags *flag)
{
	if (str[i - 1] != '.')
		flag->star = 1;
	if (str[i - 1] == '.' && flag->star == 1)
		flag->star = 3;
	if (str[i - 1] == '.' && flag->star != 3)
		flag->star = 2;
}

char		*ft_strjoin_free(const char *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*new;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
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
	free((char *)(s1));
	return (new);
}
