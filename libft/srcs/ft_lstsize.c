/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:19:39 by leickmay          #+#    #+#             */
/*   Updated: 2021/01/09 10:46:53 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*current;

	i = 1;
	if (lst == 0)
		return (0);
	current = lst;
	while (current->next != NULL)
	{
		current = current->next;
		i++;
	}
	return (i);
}
