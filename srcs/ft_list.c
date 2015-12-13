/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 03:11:46 by nle-bret          #+#    #+#             */
/*   Updated: 2015/11/30 07:36:19 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_tpush_back(t_tetri **l, t_pos *pos, char n)
{
	t_tetri	*list;

	list = *l;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_create_elem(pos, n);
	}
	else
		*l = ft_create_elem(pos, n);
}

t_tetri	*ft_create_elem(t_pos *pos, char n)
{
	t_tetri	*list;

	if ((list = (t_tetri*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	list->next = NULL;
	list->pos = pos;
	list->n = n;
	return (list);
}
