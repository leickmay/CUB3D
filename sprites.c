/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:23:31 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/03 11:49:03 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	sprite_matrix(t_data *data, int i)
{
	data->sprite_y = data->sprite[i].x - (data->pos_x - 0.5);
	data->sprite_x = data->sprite[i].y - (data->pos_y - 0.5);
	data->inv_det = 1.0 / (data->plane_x * data->dir_y - data->dir_x * \
	data->plane_y);
	data->transform_x = data->inv_det * (data->dir_y * data->sprite_x - \
	data->dir_x * data->sprite_y);
	data->transform_y = data->inv_det * (-data->plane_y * data->sprite_x + \
	data->plane_x * data->sprite_y);
	data->sprite_screen_x = (int)((data->res_x / 2) * (1 + data->transform_x / \
	data->transform_y));
}

void	sprite_find_draw(t_data *data)
{
	data->sprite_height = abs((int)(data->res_y / data->transform_y));
	data->draw_start_y = data->res_y / 2 - data->sprite_height / 2;
	if (data->draw_start_y < 0)
		data->draw_start_y = 0;
	data->draw_end_y = data->sprite_height / 2 + data->res_y / 2;
	if (data->draw_end_y >= data->res_y)
		data->draw_end_y = data->res_y;
	data->sprite_width = abs((int)(data->res_y / data->transform_y));
	data->draw_start_x = data->sprite_screen_x - data->sprite_width / 2;
	if (data->draw_start_x < 0)
		data->draw_start_x = 0;
	data->draw_end_x = data->sprite_width / 2 + data->sprite_screen_x;
	if (data->draw_end_x >= data->res_x)
		data->draw_end_x = data->res_x - 1;
}

void	draw_sprite(t_data *data, t_img *img, t_img *sprite, int stripe)
{
	t_bits_img	bits;
	int			y;
	int			d;

	bits.text_x = (int)(256 * (stripe - (data->sprite_screen_x - \
	data->sprite_width / 2)) * TEXTUREWIDTH / data->sprite_width) / 256;
	if (data->transform_y > 0 && stripe > 0 && stripe < data->res_x && \
	data->transform_y < data->z_buffer[stripe])
	{
		y = data->draw_start_y;
		while (y < data->draw_end_y)
		{
			d = y * 256 - data->res_y * 128 + data->sprite_height * 128;
			bits.text_y = ((d * TEXTUREHEIGHT) / data->sprite_height) / 256;
			bits.pixel = (y * img->line_bytes) + (stripe * 4);
			if ((int)sprite->buffer[(TEXTUREHEIGHT * bits.text_y * 4) + \
			bits.text_x * 4] != 0)
				write_sprite_bits(sprite, img, &bits);
			y++;
		}
	}
}

void	create_img_sprite(t_data *data, t_img *sprite, t_img *trap)
{
	sprite->img = mlx_xpm_file_to_image(data->ptr, data->s, &sprite->width, \
	&sprite->height);
	sprite->buffer = mlx_get_data_addr(sprite->img, &sprite->pixel_bits, \
	&sprite->line_bytes, &sprite->endian);
	sort_sprite_distance(data);
	trap->img = mlx_xpm_file_to_image(data->ptr, "pics/Boo_64.xpm", \
	&trap->width, &trap->height);
	trap->buffer = mlx_get_data_addr(trap->img, &trap->pixel_bits, \
	&trap->line_bytes, &trap->endian);
}

void	set_sprites(t_data *data, t_img *img)
{
	int		i;
	int		stripe;
	t_img	sprite;
	t_img	trap;

	i = 0;
	create_img_sprite(data, &sprite, &trap);
	sort_sprite_distance(data);
	while (i < data->nb_sprites)
	{
		sprite_matrix(data, i);
		sprite_find_draw(data);
		stripe = data->draw_start_x - 1;
		while (++stripe < data->draw_end_x)
		{
			if (data->sprite[i].tex == '2')
				draw_sprite(data, img, &sprite, stripe);
			if (data->sprite[i].tex == '3')
				draw_sprite(data, img, &trap, stripe);
		}
		i++;
	}
}
