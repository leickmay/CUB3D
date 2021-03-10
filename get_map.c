/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:43:34 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/10 11:14:10 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

char	*fill_map_bis(char *tmp_map, char *line)
{
	if (!(tmp_map = ft_strdup(line)))
		ft_error('m');
	free(line);
	return (tmp_map);
}

char	**fill_map(char *argv, char **tmp_map)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (check_map_started(line) == 1)
			break ;
		free(line);
	}
	i = 1;
	if (!(tmp_map[0] = ft_strdup(line)))
		ft_error('m');
	free(line);
	while (get_next_line(fd, &line))
	{
		if (!(tmp_map[i] = ft_strdup(line)))
			ft_error('m');
		free(line);
		i++;
	}
	tmp_map[i] = fill_map_bis(tmp_map[i], line);
	close(fd);
	return (tmp_map);
}

void	get_map(char *argv, t_data *data)
{
	char	**tmp_map;
	int		i;

	data->rows = get_rows(argv);
	if (!(tmp_map = malloc(sizeof(char *) * (data->rows + 2))))
		ft_error('m');
	tmp_map = fill_map(argv, tmp_map);
	tmp_map[data->rows + 1] = malloc(sizeof(char));
	tmp_map[data->rows + 1][0] = '\0';
	data->columns = 0;
	i = 0;
	while (i <= data->rows)
	{
		if (ft_strlen(tmp_map[i]) > (size_t)data->columns)
			data->columns = ft_strlen(tmp_map[i]);
		i++;
	}
	ft_add_space(data, tmp_map);
	data->map = tmp_map;
	get_player_start(data);
	get_sprites(data);
	ft_check_map_error(data);
}

void	check_nb_player(t_data *data)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	x = 0;
	i = 0;
	while (data->map[y][x])
	{
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'N' || data->map[y][x] == 'S' || \
			data->map[y][x] == 'E' || data->map[y][x] == 'W')
				i++;
			x++;
		}
		x = 0;
		y++;
	}
	if (i == 0)
		ft_error('p');
	if (i > 1)
		ft_error('P');
}

void	get_player_start(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	x = 0;
	check_nb_player(data);
	while (data->map[y][x])
	{
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'N' || data->map[y][x] == 'S' || \
			data->map[y][x] == 'E' || data->map[y][x] == 'W')
				break ;
			x++;
		}
		if (data->map[y][x] == 'N' || data->map[y][x] == 'S' || \
		data->map[y][x] == 'E' || data->map[y][x] == 'W')
			break ;
		x = 0;
		y++;
	}
	set_player_info(data, y, x);
}
