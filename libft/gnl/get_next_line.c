/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:55:52 by leickmay          #+#    #+#             */
/*   Updated: 2021/01/09 13:56:51 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		search_n_gnl(char *save)
{
	if (!save)
		return (0);
	while (*save)
	{
		if (*save == '\n')
			return (1);
		save++;
	}
	return (0);
}

char	*extract_line_gnl(char *save)
{
	int		i;
	char	*str;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\0')
		str = ft_strdup_gnl(save);
	else
		str = ft_substr_gnl(save, 0, i);
	return (str);
}

char	*save_str_gnl(char *save)
{
	int		i;
	char	*str;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	str = ft_substr_gnl(save, i + 1, (int)ft_strlen_gnl(save) - i - 1);
	free(save);
	return (str);
}

int		get_next_line(int fd, char **line)
{
	char static	*save;
	char		buff[2];
	int			i;

	i = 1;
	if (fd < 0 || !line)
		return (-1);
	while (search_n_gnl(save) == 0 && i != 0)
	{
		buff[0] = 0;
		if ((i = read(fd, buff, 1)) == -1)
			return (-1);
		buff[1] = 0;
		save = ft_strjoin_gnl(save, buff);
	}
	*line = extract_line_gnl(save);
	save = save_str_gnl(save);
	if (i == 0)
		return (0);
	return (1);
}
