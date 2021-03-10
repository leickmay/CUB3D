/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:28:49 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/10 10:47:14 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	get_resolution(char *argv, int *res_x, int *res_y)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (line[0] == 'R')
			break ;
		free(line);
	}
	if (line[0] != 'R' || line[1] != ' ')
		ft_error('r');
	i = 1;
	i = ft_skip_spaces(line, i);
	i = ft_get_digit(line, i, res_x);
	i = ft_skip_spaces(line, i);
	i = ft_get_digit(line, i, res_y);
	i = ft_skip_spaces(line, i);
	if (line[i])
		ft_error('r');
	free(line);
	close(fd);
}

void	get_path_texture(char *argv, char **path, char *dir)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if ((line[0] == dir[0]) && (line[1] == dir[1]))
			break ;
		free(line);
	}
	if (line[0] != dir[0] || line[1] != dir[1] || line[2] != ' ')
		ft_error('t');
	i = 2;
	i = ft_skip_spaces(line, i);
	ft_get_str(line, i, path);
	free(line);
	ft_check_xpm_file(path);
	close(fd);
}

void	get_sprite_path(char *argv, char **path)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (line[0] == 'S' && line[1] == ' ')
			break ;
		free(line);
	}
	if (line[0] != 'S' || line[1] != ' ')
		ft_error('s');
	i = 1;
	i = ft_skip_spaces(line, i);
	ft_get_str(line, i, path);
	free(line);
	ft_check_xpm_file(path);
	close(fd);
}

void	get_color(char *argv, t_rgb *f, char c)
{
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (line[0] == c && line[1] == ' ')
			break ;
		free(line);
	}
	if (line[0] != c || line[1] != ' ')
		ft_error(c);
	ft_fill_rgb(f, line);
	free(line);
	ft_check_rgb(f);
}

void	ft_parse_map(char *argv, t_data *data)
{
	int		fd;

	if ((fd = open(argv, O_DIRECTORY) != -1))
		ft_error('D');
	if (open(argv, O_RDONLY) < 0)
		ft_error('e');
	check_cub_ext(argv);
	get_map(argv, data);
	get_resolution(argv, &data->res_x, &data->res_y);
	if (data->res_y > 1440)
		data->res_y = 1440;
	if (data->res_x > 2560)
		data->res_x = 2560;
	if (data->res_y <= 0 || data->res_x <= 0)
		ft_error('r');
	get_path_texture(argv, &data->no, "NO");
	get_path_texture(argv, &data->so, "SO");
	get_path_texture(argv, &data->we, "WE");
	get_path_texture(argv, &data->ea, "EA");
	get_sprite_path(argv, &data->s);
	get_color(argv, &data->f, 'F');
	get_color(argv, &data->c, 'C');
	ft_check_doubles_list(argv);
}
