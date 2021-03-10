/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:19:49 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/10 10:29:34 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int		get_rows(char *argv)
{
	int		fd;
	int		i;
	char	*line;

	i = 1;
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (check_map_started(line))
			break ;
		free(line);
	}
	free(line);
	while (get_next_line(fd, &line))
	{
		i++;
		free(line);
	}
	free(line);
	close(fd);
	return (i);
}

void	set_player_info(t_data *data, int y, int x)
{
	data->s_pos_dir = data->map[y][x];
	data->pos_x = x;
	data->pos_y = y;
	data->s_pos_x = x;
	data->s_pos_y = y;
	data->map[y][x] = '0';
}

void	set_sprite_info(t_data *data, int y, int x, int i)
{
	data->sprite[i].x = x;
	data->sprite[i].y = y;
	data->sprite[i].tex = (data->map[y][x]);
}

void	ft_check_doubles_list(char *argv)
{
	ft_check_doubles_one_char(argv, 'R');
	ft_check_doubles_one_char(argv, 'N');
	ft_check_doubles_one_char(argv, 'W');
	ft_check_doubles_one_char(argv, 'E');
	ft_check_doubles_s(argv, 'S');
	ft_check_doubles_one_char(argv, 'F');
	ft_check_doubles_one_char(argv, 'C');
	ft_check_elements(argv);
}

void	check_cub_ext(char *argv)
{
	char	*str;
	int		len;

	str = ft_strdup(argv);
	len = ft_strlen(str);
	if (str[len - 1] != 'b')
		ft_error('u');
	if (str[len - 2] != 'u')
		ft_error('u');
	if (str[len - 3] != 'c')
		ft_error('u');
	free(str);
}
