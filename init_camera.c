/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:29:10 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/03 12:00:27 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	init_camera_plan(t_data *data)
{
	if (data->s_pos_dir == 'N')
	{
		data->plane_x = 0;
		data->plane_y = 0.60;
	}
	if (data->s_pos_dir == 'S')
	{
		data->plane_x = 0;
		data->plane_y = -0.60;
	}
	if (data->s_pos_dir == 'E')
	{
		data->plane_x = 0.60;
		data->plane_y = 0;
	}
	if (data->s_pos_dir == 'W')
	{
		data->plane_x = -0.60;
		data->plane_y = 0;
	}
}

void	init_camera_dir(t_data *data)
{
	if (data->s_pos_dir == 'N')
	{
		data->dir_x = -1;
		data->dir_y = 0;
	}
	if (data->s_pos_dir == 'S')
	{
		data->dir_x = 1;
		data->dir_y = 0;
	}
	if (data->s_pos_dir == 'E')
	{
		data->dir_x = 0;
		data->dir_y = 1;
	}
	if (data->s_pos_dir == 'W')
	{
		data->dir_x = 0;
		data->dir_y = -1;
	}
}
