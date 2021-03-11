/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_bis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 11:08:39 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/11 14:00:07 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	ft_add_space(t_data *data, char **tmp_map)
{
	int		y;
	int		i;
	int		len;
	char	*new_line;

	y = -1;
	if (!(new_line = malloc(sizeof(char) * (data->columns + 1))))
		ft_error('m');
	while (++y <= data->rows)
	{
		len = ft_strlen(tmp_map[y]);
		if (len < data->columns)
		{
			i = -1;
			while (++i < len)
				new_line[i] = tmp_map[y][i];
			i--;
			while (++i < data->columns)
				new_line[i] = ' ';
			new_line[i] = '\0';
			free(tmp_map[y]);
			if (!(tmp_map[y] = ft_strdup(new_line)))
				ft_error('m');
		}
	}
	free(new_line);
}

int		check_map_started(char *line)
{
	int		i;

	i = 0;
	if (check_space_line(line) == 1)
		return (0);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '0' && line[i] != '1' && line[i] != \
		'2' && line[i] != '3')
			return (0);
		i++;
	}
	return (1);
}

int		check_space_line(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
