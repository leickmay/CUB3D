/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:22:01 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/10 11:14:46 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	ft_error(char c)
{
	ft_putstr_fd("ERROR\n", 2);
	if (c == 'a')
		ft_putstr_fd("MISSING ARGUMENT\n", 2);
	else if (c == 'r')
		ft_putstr_fd("MISSING WINDOW RESOLUTION\n", 2);
	else if (c == 'm')
		ft_putstr_fd("WTF UN MALLOC A PETE\n", 2);
	else if (c == 't')
		ft_putstr_fd("MISSING A TEXTURE PATH\n", 2);
	else if (c == 's')
		ft_putstr_fd("MISSING SPRITE TEXTURE\n", 2);
	else if (c == 'F')
		ft_putstr_fd("MISSING FLOOR COLOR\n", 2);
	else if (c == 'C')
		ft_putstr_fd("MISSING SKY COLOR\n", 2);
	else if (c == 'c')
		ft_putstr_fd("BAD COLOR SETTINGS\n", 2);
	else if (c == 'p')
		ft_putstr_fd("NO PLAYER\n", 2);
	else if (c == 'P')
		ft_putstr_fd("TOO MUCH PLAYERS\n", 2);
	else
		ft_error_bis(c);
	exit(0);
}

void	ft_error_bis(char c)
{
	if (c == 'M')
		ft_putstr_fd("MAP ERROR\n", 2);
	if (c == 'd')
		ft_putstr_fd("DOUBLE PARAMETER\n", 2);
	if (c == 'e')
		ft_putstr_fd("PASS PROBLEM, FILE DOESN'T EXIST\n", 2);
	if (c == 'f')
		ft_putstr_fd("TEXTURES AND SPRITES MUST BE XPM FILES\n", 2);
	if (c == 'b')
		ft_putstr_fd("2ND ARGUMENT INVALID\n", 2);
	if (c == 'c')
		ft_putstr_fd("CAN'T CREATE BITMAP\n", 2);
	if (c == 'u')
		ft_putstr_fd("MAP FILE MUST HAVE CUB EXTENTION\n", 2);
	if (c == 'E')
		ft_putstr_fd("THERE IS AN EMPTY LINE IN THE MAP\n", 2);
	if (c == 'D')
		ft_putstr_fd("MAP FILE IS A DIRECTORY\n", 2);
	if (c == 'l')
		ft_putstr_fd("FORBIDDEN CHAR IN MAP DESCRIPTOR\n", 2);
}

int		ft_exit(void)
{
	exit(0);
}
