/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:29:37 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/03 11:30:06 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	get_nb_sprites(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	data->nb_sprites = 0;
	while (data->map[y][x])
	{
		while (data->map[y][x])
		{
			if (data->map[y][x] == '2' || data->map[y][x] == '3')
				data->nb_sprites++;
			x++;
		}
		x = 0;
		y++;
	}
}

void	get_sprite_pos(t_data *data)
{
	int		i;
	int		y;
	int		x;

	i = 0;
	while (i < data->nb_sprites)
	{
		y = 0;
		x = 0;
		while (data->map[y][x])
		{
			while (data->map[y][x])
			{
				if (data->map[y][x] == '2' || data->map[y][x] == '3')
				{
					set_sprite_info(data, y, x, i);
					i++;
				}
				x++;
			}
			x = 0;
			y++;
		}
	}
}

void	sort_sprite_distance(t_data *data)
{
	int			i;
	t_sprite	tmp;

	i = 0;
	while (i < data->nb_sprites)
	{
		data->sprite[i].distance = sqrt((data->pos_x - data->sprite[i].x) * \
		(data->pos_x - data->sprite[i].x) + (data->pos_y - data->sprite[i].y) \
		* (data->pos_y - data->sprite[i].y));
		i++;
	}
	i = 0;
	while (i < data->nb_sprites - 1)
	{
		if (data->sprite[i].distance < data->sprite[i + 1].distance)
		{
			tmp = data->sprite[i];
			data->sprite[i] = data->sprite[i + 1];
			data->sprite[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
}

void	get_sprites(t_data *data)
{
	get_nb_sprites(data);
	if (!(data->sprite = malloc(sizeof(t_sprite) * data->nb_sprites + 1)))
		ft_error('m');
	get_sprite_pos(data);
	sort_sprite_distance(data);
}
