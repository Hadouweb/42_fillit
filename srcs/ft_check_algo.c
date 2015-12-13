/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 03:54:20 by nle-bret          #+#    #+#             */
/*   Updated: 2015/12/04 21:22:06 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_add_char(t_tetri *list, char **map, t_pos p)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		map[p.y + list->pos[i].y][p.x + list->pos[i].x] = list->n;
		i++;
	}
}

int		ft_verify_tetri(t_tetri *list, char **map, t_pos p, int max)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (p.y + list->pos[i].y >= max || p.x + list->pos[i].x >= max)
			return (0);
		if (map[p.y + list->pos[i].y][p.x + list->pos[i].x] != '.')
			return (0);
		i++;
	}
	return (1);
}

void	ft_remove_list(t_pos *pos, char **map, t_pos p)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		map[p.y + pos[i].y][p.x + pos[i].x] = '.';
		i++;
	}
}

int		ft_count_tetri(t_tetri *list)
{
	int		i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

double	ft_sqrt(double nb)
{
	double	calc;
	double	diff;

	diff = 0.0;
	if (nb == 0.0 || nb == 1.0)
		return (nb);
	calc = nb;
	while (calc != diff)
	{
		diff = calc;
		calc = 0.5 * (calc + nb / calc);
	}
	return (calc);
}
