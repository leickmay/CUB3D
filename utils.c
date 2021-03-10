/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:46:19 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/09 10:09:55 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int		ft_skip_spaces(char *str, int i)
{
	while (str[i] == ' ')
		i++;
	return (i);
}

int		ft_get_digit(char *str, int i, int *digit)
{
	int		j;
	char	*nb;

	j = 0;
	while (ft_isdigit(str[i]))
	{
		i++;
		j++;
	}
	i -= j;
	if (!(nb = ft_substr(str, i, j)))
		ft_error('m');
	*digit = ft_atoi(nb);
	free(nb);
	return (i + j);
}

void	ft_get_str(char *str, int i, char **path)
{
	int		j;

	j = 0;
	while (str[i] != ' ' && str[i])
	{
		j++;
		i++;
	}
	i -= j;
	if (!(*path = ft_substr(str, i, j)))
		ft_error('m');
	j += i;
	j = ft_skip_spaces(str, j);
	if (str[j])
		ft_error('t');
}

int		ft_check_empty_line(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == '2')
			return (1);
		i++;
	}
	return (0);
}

void	ft_check_xpm_file(char **path)
{
	int		fd;
	int		len;
	char	*str;

	str = strdup(*path);
	len = ft_strlen(str);
	if ((fd = open(str, O_RDONLY)) < 1)
		ft_error('e');
	close(fd);
	if (str[len - 1] != 'm')
		ft_error('f');
	if (str[len - 2] != 'p')
		ft_error('f');
	if (str[len - 3] != 'x')
		ft_error('f');
	free(str);
}
