/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:25:46 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/10 11:16:53 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int		is_in_elements(char c)
{
	char	*elements;
	int		i;

	elements = "RNSWEFC 1230\0";
	i = 0;
	while (elements[i])
	{
		if (c == elements[i])
			return (1);
		if (c == '\0')
			return (1);
		i++;
	}
	return (0);
}

void	ft_check_elements(char *argv)
{
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (check_map_started(line))
			break ;
		if (is_in_elements(line[0]) == 0)
			ft_error('l');
		if (line[0] == ' ')
			if (check_space_line(line) == 0)
				ft_error('l');
		free(line);
	}
	free(line);
	close(fd);
}

void	ft_check_doubles_one_char(char *argv, char c)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (line[0] == c)
			i++;
		if (i > 1)
			ft_error('d');
		free(line);
	}
	free(line);
	close(fd);
}

void	ft_check_doubles_s(char *argv, char c)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (line[0] == c)
			i++;
		if (i > 2)
			ft_error('d');
		free(line);
	}
	free(line);
	close(fd);
}
