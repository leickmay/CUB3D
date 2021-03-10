/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:20:32 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/10 11:07:34 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	restart_game(t_data *data)
{
	t_img	img;

	init_camera_dir(data);
	init_camera_plan(data);
	img.img = mlx_new_image(data->ptr, data->res_x, data->res_y);
	img.buffer = \
	mlx_get_data_addr(img.img, &img.pixel_bits, &img.line_bytes, &img.endian);
	data->life = 20;
	data->pos_x = data->s_pos_x;
	data->pos_y = data->s_pos_y;
	update_img(data, &img);
}

void	set_data_save(int argc, char **argv, t_data *data)
{
	data->save = 0;
	if (argc == 3)
	{
		if (ft_strncmp(argv[2], "--save", 6) == 0)
		{
			data->save = 1;
		}
		else
			ft_error('b');
	}
	if (argc == 1 || argc > 3)
		ft_error('a');
}

int		main(int argc, char **argv)
{
	t_data		data;
	t_img		img;

	set_data_save(argc, argv, &data);
	data.life = 20;
	ft_parse_map(argv[1], &data);
	data.ptr = mlx_init();
	data.win = mlx_new_window(data.ptr, data.res_x, data.res_y, "CUB3D");
	init_camera_dir(&data);
	init_camera_plan(&data);
	img.img = mlx_new_image(data.ptr, data.res_x, data.res_y);
	img.buffer = \
	mlx_get_data_addr(img.img, &img.pixel_bits, &img.line_bytes, &img.endian);
	update_img(&data, &img);
	mlx_hook(data.win, 17, 1L << 0, ft_exit, &data);
	mlx_hook(data.win, 02, 1L << 0, deal_key_press, &data);
	mlx_loop(data.ptr);
}
