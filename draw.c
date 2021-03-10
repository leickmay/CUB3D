/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:13:12 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/03 11:59:57 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	draw_floor_sky(t_data *data, t_img *img, int x)
{
	int				y;
	int				pixel;
	unsigned int	color;

	y = 0;
	while (y < data->res_y)
	{
		if (y <= data->draw_start)
			color = data->c.color;
		if (y >= data->draw_end)
			color = data->f.color;
		pixel = (y * img->line_bytes) + (x * 4);
		img->buffer[pixel + 0] = (color) & 0xFF;
		img->buffer[pixel + 1] = (color >> 8) & 0xFF;
		img->buffer[pixel + 2] = (color >> 16) & 0xFF;
		img->buffer[pixel + 3] = (color >> 24);
		y++;
	}
}

void	set_texture_type(t_data *data, t_img *texture)
{
	if (data->side == 1 && data->ray_dir_y > 0)
		texture->img = mlx_xpm_file_to_image(data->ptr, \
		data->ea, &texture->width, &texture->height);
	if (data->side == 1 && data->ray_dir_y < 0)
		texture->img = mlx_xpm_file_to_image(data->ptr, \
		data->we, &texture->width, &texture->height);
	if (data->side == 0 && data->ray_dir_x > 0)
		texture->img = mlx_xpm_file_to_image(data->ptr, \
		data->so, &texture->width, &texture->height);
	if (data->side == 0 && data->ray_dir_x < 0)
		texture->img = mlx_xpm_file_to_image(data->ptr, \
		data->no, &texture->width, &texture->height);
	texture->buffer = mlx_get_data_addr(texture->img, &texture->pixel_bits, \
	&texture->line_bytes, &texture->endian);
}

void	write_texture_bits(t_data *data, t_img *img, t_img *texture, int x)
{
	int		text_y;
	int		y;
	int		pixel;

	y = data->draw_start;
	while (y < data->draw_end)
	{
		text_y = (int)data->text_pos & (TEXTUREHEIGHT - 1);
		data->text_pos += data->step;
		pixel = (y * img->line_bytes) + (x * 4);
		img->buffer[pixel] = \
		texture->buffer[(TEXTUREHEIGHT * text_y * 4) + data->text_x * 4];
		img->buffer[pixel + 1] = \
		texture->buffer[TEXTUREHEIGHT * text_y * 4 + data->text_x * 4 + 1];
		img->buffer[pixel + 2] = \
		texture->buffer[TEXTUREHEIGHT * text_y * 4 + data->text_x * 4 + 2];
		img->buffer[pixel + 3] = \
		texture->buffer[TEXTUREHEIGHT * text_y * 4 + data->text_x * 4 + 3];
		y++;
	}
}

void	draw_textures(t_data *data, t_img *img, t_img *texture, int x)
{
	if (data->side == 0)
		data->wall_x = data->pos_x + data->perp_wall_dist * data->ray_dir_y;
	else
		data->wall_x = data->pos_y + data->perp_wall_dist * data->ray_dir_x;
	data->wall_x -= floor(data->wall_x);
	data->text_x = (int)(data->wall_x * (double)(TEXTUREWIDTH));
	if (data->side == 0 && data->ray_dir_x > 0)
		data->text_x = TEXTUREWIDTH - data->text_x - 1;
	if (data->side == 1 && data->ray_dir_y < 0)
		data->text_x = TEXTUREWIDTH - data->text_x - 1;
	data->step = (double)TEXTUREHEIGHT / (double)data->lineheight;
	data->text_pos = \
	(data->draw_start - data->res_y / 2 + data->lineheight / 2) * data->step;
	set_texture_type(data, texture);
	write_texture_bits(data, img, texture, x);
}

void	write_sprite_bits(t_img *sprite, t_img *img, t_bits_img *bits)
{
	img->buffer[bits->pixel] = \
	sprite->buffer[(TEXTUREHEIGHT * bits->text_y * 4) + bits->text_x * 4];
	img->buffer[bits->pixel + 1] = \
	sprite->buffer[(TEXTUREHEIGHT * bits->text_y * 4) + bits->text_x * 4 + 1];
	img->buffer[bits->pixel + 2] = \
	sprite->buffer[(TEXTUREHEIGHT * bits->text_y * 4) + bits->text_x * 4 + 2];
	img->buffer[bits->pixel + 3] = \
	sprite->buffer[(TEXTUREHEIGHT * bits->text_y * 4) + bits->text_x * 4 + 3];
}
