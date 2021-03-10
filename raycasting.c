/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 13:00:22 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/09 15:58:09 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	set_ray(t_data *data, int x, t_img *img, t_img *texture)
{
	data->camera_x = 2 * x / (double)data->res_x - 1;
	data->ray_dir_x = data->dir_x + data->plane_x * data->camera_x;
	data->ray_dir_y = data->dir_y + data->plane_y * data->camera_x;
	data->map_y = (int)(data->pos_y);
	data->map_x = (int)(data->pos_x);
	data->delta_dist_x = sqrt(1 + (data->ray_dir_y * data->ray_dir_y) / \
	(data->ray_dir_x * data->ray_dir_x));
	data->delta_dist_y = sqrt(1 + (data->ray_dir_x * data->ray_dir_x) / \
	(data->ray_dir_y * data->ray_dir_y));
	set_side_dist(data);
	dda_algorithm(data);
	set_wall_height(data);
	draw_floor_sky(data, img, x);
	draw_textures(data, img, texture, x);
}

void	set_side_dist(t_data *data)
{
	if (data->ray_dir_x < 0)
	{
		data->step_x = -1;
		data->side_dist_x = (data->pos_y - data->map_y) * data->delta_dist_x;
	}
	else
	{
		data->step_x = 1;
		data->side_dist_x = \
		(data->map_y + 1.0 - data->pos_y) * data->delta_dist_x;
	}
	if (data->ray_dir_y < 0)
	{
		data->step_y = -1;
		data->side_dist_y = \
		(data->pos_x - data->map_x) * data->delta_dist_y;
	}
	else
	{
		data->step_y = 1;
		data->side_dist_y = \
		(data->map_x + 1.0 - data->pos_x) * data->delta_dist_y;
	}
}

void	set_wall_height(t_data *data)
{
	if (data->side == 0)
		data->perp_wall_dist = \
		(data->map_y - data->pos_y + (1 - data->step_x) / 2) / data->ray_dir_x;
	else
		data->perp_wall_dist = \
		(data->map_x - data->pos_x + (1 - data->step_y) / 2) / data->ray_dir_y;
	data->lineheight = (int)(data->res_y / data->perp_wall_dist);
	data->draw_start = data->res_y / 2 - data->lineheight / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->lineheight / 2 + data->res_y / 2;
	if (data->draw_end >= data->res_y)
		data->draw_end = data->res_y;
}

void	dda_algorithm(t_data *data)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (data->side_dist_x < data->side_dist_y)
		{
			data->side_dist_x += data->delta_dist_x;
			data->map_y += data->step_x;
			data->side = 0;
		}
		else
		{
			data->side_dist_y += data->delta_dist_y;
			data->map_x += data->step_y;
			data->side = 1;
		}
		if (data->map[data->map_y][data->map_x] == '1')
			hit = 1;
	}
}

void	update_img(t_data *data, t_img *img)
{
	int		x;
	t_img	texture;

	x = -1;
	if (!(data->z_buffer = malloc(sizeof(double) * data->res_x)))
		ft_error('m');
	while (++x < data->res_x)
	{
		set_ray(data, x, img, &texture);
		data->z_buffer[x] = data->perp_wall_dist;
	}
	set_sprites(data, img);
	x = -1;
	while (++x < data->res_x)
		display_life(data, img, x);
	if (data->save == 1)
		create_bitmap_image(data, img);
	mlx_put_image_to_window(data->ptr, data->win, img->img, 0, 0);
	mlx_string_put(data->ptr, data->win, data->res_x / 2, \
	data->res_y / 30, 0x000000, "LIFE");
	if (data->life < 0)
		game_over(data);
	free(data->z_buffer);
	mlx_do_sync(data->ptr);
}
