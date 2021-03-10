/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:15:54 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/04 13:28:42 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	create_bitmap_header(t_data *data, t_img *img, int fd)
{
	int		i;
	int		tmp;

	write(fd, "BM", 2);
	tmp = 54 + 4 * data->res_x * data->res_y;
	write(fd, &tmp, 4);
	tmp = 0;
	write(fd, &tmp, 4);
	tmp = 54;
	write(fd, &tmp, 4);
	tmp = 40;
	write(fd, &tmp, 4);
	tmp = data->res_x;
	write(fd, &data->res_x, 4);
	tmp = data->res_y;
	write(fd, &data->res_y, 4);
	tmp = 1;
	write(fd, &tmp, 2);
	write(fd, &img->pixel_bits, 2);
	tmp = 0;
	i = 0;
	while (i++ < 24)
		write(fd, &tmp, 1);
}

void	create_bitmap_image(t_data *data, t_img *img)
{
	int		y;
	int		x;
	int		fd;

	if ((fd = open("save.bmp", O_CREAT | O_RDWR, S_IWUSR | S_IRUSR)) < 0)
		ft_error('c');
	create_bitmap_header(data, img, fd);
	y = data->res_y - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < data->res_x)
		{
			write(fd, &img->buffer[y * img->line_bytes + x * 4], 4);
			x++;
		}
		y--;
	}
	exit(0);
}
