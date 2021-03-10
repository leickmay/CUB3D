/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 15:36:12 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/03 11:12:29 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	write_resize_bits(t_img *game_over, t_img *resize, t_bits_img *bits)
{
	resize->buffer[bits->pixel] = \
	game_over->buffer[(game_over->width * bits->text_y * 4) + bits->text_x * 4];
	resize->buffer[bits->pixel + 1] = game_over->buffer[game_over->width * \
	bits->text_y * 4 + bits->text_x * 4 + 1];
	resize->buffer[bits->pixel + 2] = game_over->buffer[game_over->width * \
	bits->text_y * 4 + bits->text_x * 4 + 2];
	resize->buffer[bits->pixel + 3] = game_over->buffer[game_over->width * \
	bits->text_y * 4 + bits->text_x * 4 + 3];
}

void	resize_img(t_data *data, t_img *game_over, t_img *resize)
{
	t_bits_img	bits;
	int			y;
	int			x;

	bits.step_y = (double)game_over->height / (double)data->res_y;
	bits.step_x = (double)game_over->width / (double)data->res_x;
	bits.text_pos_x = 0;
	x = -1;
	while (++x < data->res_x)
	{
		bits.text_x = (int)bits.text_pos_x;
		bits.text_pos_x += bits.step_x;
		y = -1;
		bits.text_pos_y = 0;
		while (++y < data->res_y)
		{
			bits.text_y = (int)bits.text_pos_y;
			bits.text_pos_y += bits.step_y;
			bits.pixel = (y * resize->line_bytes) + (x * 4);
			write_resize_bits(game_over, resize, &bits);
		}
	}
}

void	game_over(t_data *data)
{
	t_img	game_over;
	t_img	resize;

	game_over.img = mlx_xpm_file_to_image(data->ptr, \
	"pics/game_over_small.xpm", &game_over.width, &game_over.height);
	game_over.buffer = mlx_get_data_addr(game_over.img, &game_over.pixel_bits, \
	&game_over.line_bytes, &game_over.endian);
	resize.img = mlx_new_image(data->ptr, data->res_x, data->res_y);
	resize.buffer = \
	mlx_get_data_addr(resize.img, &resize.pixel_bits, &resize.line_bytes, \
	&resize.endian);
	resize_img(data, &game_over, &resize);
	mlx_put_image_to_window(data->ptr, data->win, resize.img, 0, 0);
}

void	display_life(t_data *data, t_img *img, int x)
{
	int				y;
	int				pixel;
	int				length;
	int				pdv_lost;
	unsigned int	color;

	if (x > (data->res_x / 16) && x < (data->res_x - data->res_x / 16))
	{
		y = (data->res_y / 40) - 1;
		color = 0x02CB11;
		pdv_lost = ((data->res_x - data->res_x / 16) - data->res_x / 16) / 20 \
		* (20 - data->life);
		length = (data->res_x - data->res_x / 16) - pdv_lost;
		if (x > length)
			color = 0xFF0000;
		while (++y < (data->res_y / 20))
		{
			pixel = (y * img->line_bytes) + (x * 4);
			img->buffer[pixel + 0] = (color) & 0xFF;
			img->buffer[pixel + 1] = (color >> 8) & 0xFF;
			img->buffer[pixel + 2] = (color >> 16) & 0xFF;
			img->buffer[pixel + 3] = (color >> 24);
		}
	}
}

void	check_trap(t_data *data)
{
	if (data->map[(int)data->pos_y][(int)data->pos_x] == '3')
		data->life--;
}
