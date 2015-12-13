/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heuristic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 07:28:31 by hdebard           #+#    #+#             */
/*   Updated: 2015/12/04 21:48:49 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_heuristic(t_tetri *list, char **map, int max)
{
	int		i;
	int		j;

	i = (4 * ft_count_tetri(list));
	j = ft_space_counter(map, max);
	if (i > j)
		return (0);
	else
		return (1);
}

int		ft_contaminate(char **map, int x, int y, int max)
{
	if (x < 0 || x >= max || y < 0 || y >= max)
		return (0);
	if ('.' == map[y][x])
	{
		map[y][x] = '*';
		return (1
				+ ft_contaminate(map, x - 1, y, max)
				+ ft_contaminate(map, x + 1, y, max)
				+ ft_contaminate(map, x, y - 1, max)
				+ ft_contaminate(map, x, y + 1, max));
	}
	return (0);
}

void	ft_clean(char **map)
{
	int		y;
	int		x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if ('*' == map[y][x])
				map[y][x] = '.';
			x++;
		}
		y++;
	}
}

int		ft_space_counter(char **map, int max)
{
	int		y;
	int		x;
	int		count;
	int		tmp;

	y = -1;
	tmp = 0;
	count = 0;
	while (map[++y])
	{
		x = 0;
		while (map[y][x])
		{
			tmp = 0;
			if ('.' == map[y][x])
			{
				tmp = ft_contaminate(map, x, y, max);
				if (tmp > 3)
					count = count + tmp;
			}
			x++;
		}
	}
	ft_clean(map);
	return (count);
}
