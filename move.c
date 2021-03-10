/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:32:20 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/04 11:40:26 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	move_forward(int key, t_data *data)
{
	if (key == 13)
	{
		if (data->map[(int)(data->pos_y + data->dir_x * 0.5)]\
		[(int)(data->pos_x)] == '0' || data->map[(int)(data->pos_y + \
		data->dir_x * 0.5)][(int)(data->pos_x)] == '3')
			data->pos_y += data->dir_x * 0.5;
		if (data->map[(int)(data->pos_y)][(int)(data->pos_x + data->dir_y * \
		0.5)] == '0' || data->map[(int)(data->pos_y)][(int)(data->pos_x + \
		data->dir_y * 0.5)] == '3')
			data->pos_x += data->dir_y * 0.5;
	}
	if (key == 1)
	{
		if (data->map[(int)(data->pos_y - data->dir_x * 0.5)]\
		[(int)(data->pos_x)] == '0' || data->map[(int)(data->pos_y - \
		data->dir_x * 0.5)][(int)(data->pos_x)] == '3')
			data->pos_y -= data->dir_x * 0.5;
		if (data->map[(int)(data->pos_y)]\
		[(int)(data->pos_x - data->dir_y * 0.5)] == '0' || \
		data->map[(int)(data->pos_y)]\
		[(int)(data->pos_x - data->dir_y * 0.5)] == '3')
			data->pos_x -= data->dir_y * 0.5;
	}
}

void	move_side(int key, t_data *data)
{
	if (key == 2)
	{
		if (data->map[(int)(data->pos_y + data->dir_y * 0.5)]\
		[(int)(data->pos_x)] == '0' || data->map[(int)(data->pos_y + \
		data->dir_y * 0.5)][(int)(data->pos_x)] == '3')
			data->pos_y += data->dir_y * 0.5;
		if (data->map[(int)(data->pos_y)]\
		[(int)(data->pos_x - data->dir_x * 0.5)] == '0' || \
		data->map[(int)(data->pos_y)][(int)(data->pos_x - data->dir_x * 0.5)] \
		== '3')
			data->pos_x -= data->dir_x * 0.5;
	}
	if (key == 0)
	{
		if (data->map[(int)(data->pos_y - data->dir_y * 0.5)]\
		[(int)(data->pos_x)] == '0' || data->map[(int)(data->pos_y - \
		data->dir_y * 0.5)][(int)(data->pos_x)] == '3')
			data->pos_y -= data->dir_y * 0.5;
		if (data->map[(int)(data->pos_y)]\
		[(int)(data->pos_x + data->dir_x * 0.5)] == '0' || \
		data->map[(int)(data->pos_y)][(int)(data->pos_x + data->dir_x * 0.5)] \
		== '3')
			data->pos_x += data->dir_x * 0.5;
	}
}

void	rotate_camera(int key, t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	old_plane_x = data->plane_x;
	if (key == 123)
	{
		data->dir_x = data->dir_x * cos(0.15) - data->dir_y * sin(0.15);
		data->dir_y = old_dir_x * sin(0.15) + data->dir_y * cos(0.15);
		data->plane_x = data->plane_x * cos(0.15) - data->plane_y * sin(0.15);
		data->plane_y = old_plane_x * sin(0.15) + data->plane_y * cos(0.15);
	}
	if (key == 124)
	{
		data->dir_x = data->dir_x * cos(-0.15) - data->dir_y * sin(-0.15);
		data->dir_y = old_dir_x * sin(-0.15) + data->dir_y * cos(-0.15);
		data->plane_x = data->plane_x * cos(-0.15) - data->plane_y * sin(-0.15);
		data->plane_y = old_plane_x * sin(-0.15) + data->plane_y * cos(-0.15);
	}
}

int		deal_key_press(int key, void *param)
{
	t_data	*data;
	t_img	img;

	data = param;
	if (data->life > 0)
	{
		if (key == 13 || key == 1)
			move_forward(key, data);
		if (key == 0 || key == 2)
			move_side(key, data);
		if (key == 123 || key == 124)
			rotate_camera(key, data);
	}
	if (data->life <= 0)
		if (key == 15)
			restart_game(data);
	if (key == 53)
		ft_exit();
	img.img = mlx_new_image(data->ptr, data->res_x, data->res_y);
	img.buffer = \
	mlx_get_data_addr(img.img, &img.pixel_bits, &img.line_bytes, &img.endian);
	check_trap(data);
	update_img(data, &img);
	return (1);
}
