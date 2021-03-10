/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 14:35:38 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/10 11:15:25 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	ft_check_map_char(char **map, t_data *data)
{
	int		x;
	int		y;

	y = 0;
	x = 0;
	while (y <= data->rows)
	{
		while (map[y][x])
		{
			if (map[y][x] != 'N' && map[y][x] != 'S' && \
			map[y][x] != 'E' && map[y][x] != 'W' && \
			map[y][x] != '0' && map[y][x] != '1' && \
			map[y][x] != '2' && map[y][x] != ' ' && \
			map[y][x] != '3')
				ft_error('M');
			x++;
		}
		x = 0;
		y++;
	}
}

int		ft_check_map_walls(t_data *data, int x, int y)
{
	int		ret;

	ret = 0;
	if (x < 0 || y < 0 || y > data->rows || x > data->columns)
		return (0);
	if (data->map[y][x] == '1' || data->map[y][x] == '+')
		return (1);
	if (data->map[y][x] == ' ')
		return (0);
	data->map[y][x] = '+';
	ret = ft_check_map_walls(data, x + 1, y) && \
	ft_check_map_walls(data, x, y + 1) && ft_check_map_walls(data, x - 1, y) \
	&& ft_check_map_walls(data, x, y - 1);
	return (ret);
}

void	write_sprites_back(t_data *data)
{
	int i;

	i = 0;
	while (i < data->nb_sprites)
	{
		if (data->sprite[i].tex == '2')
			data->map[(int)data->sprite[i].y][(int)data->sprite[i].x] = '2';
		if (data->sprite[i].tex == '3')
			data->map[(int)data->sprite[i].y][(int)data->sprite[i].x] = '3';
		i++;
	}
}

void	ft_check_map_error(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	x = 0;
	ft_check_map_char(data->map, data);
	if (ft_check_map_walls(data, data->pos_x, data->pos_y) == 0)
		ft_error('M');
	while (data->map[y][x])
	{
		while (data->map[y][x])
		{
			if (data->map[y][x] == '+')
				data->map[y][x] = '0';
			x++;
		}
		x = 0;
		y++;
	}
	write_sprites_back(data);
}
