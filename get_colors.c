/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:40:13 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/09 10:24:30 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	ft_fill_rgb_bis(t_rgb *f, char *line, int i, int j)
{
	char	*nb;

	if (!(nb = ft_substr(line, j, i - j)))
		ft_error('m');
	if (nb[0] == '\0')
		ft_error('c');
	f->g = ft_atoi(nb);
	free(nb);
	i = ft_skip_spaces(line, i);
	if (line[i] != ',')
		ft_error('c');
	i++;
	i = ft_skip_spaces(line, i);
	j = i;
	while (ft_isdigit(line[j]))
		j++;
	if (!(nb = ft_substr(line, i, j - i)))
		ft_error('m');
	if (nb[0] == '\0')
		ft_error('c');
	f->b = ft_atoi(nb);
	j = ft_skip_spaces(line, j);
	if (line[j])
		ft_error('c');
	free(nb);
}

void	ft_fill_rgb(t_rgb *f, char *line)
{
	int		i;
	int		j;
	char	*nb;

	i = ft_skip_spaces(line, 1);
	j = i;
	while (ft_isdigit(line[j]))
		j++;
	if (!(nb = ft_substr(line, i, j - i)))
		ft_error('m');
	if (nb[0] == '\0')
		ft_error('c');
	f->r = ft_atoi(nb);
	free(nb);
	j = ft_skip_spaces(line, j);
	if (line[j] != ',')
		ft_error('c');
	j++;
	j = ft_skip_spaces(line, j);
	i = j;
	while (ft_isdigit(line[i]))
		i++;
	ft_fill_rgb_bis(f, line, i, j);
}

void	ft_check_rgb(t_rgb *f)
{
	if (f->r < 0 || f->r > 255)
		ft_error('c');
	if (f->g < 0 || f->g > 255)
		ft_error('c');
	if (f->b < 0 || f->b > 255)
		ft_error('c');
	f->color = ((f->r & 0xff) << 16) + ((f->g & 0xff) << 8) + (f->b & 0xff);
}
