/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 07:34:01 by nle-bret          #+#    #+#             */
/*   Updated: 2015/12/14 00:24:06 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_pos(t_pos *pos)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		ft_putnbr(pos[i].y);
		ft_putnbr(pos[i].x);
		ft_putstr("\n");
		i++;
	}
	ft_putstr("\n");
}

void	ft_print_map(char **map)
{
	int		y;
	int		x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			ft_putchar(map[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
	ft_putchar('\n');
}

void	ft_print_error(void)
{
	ft_putstr("error\n");
	exit(1);
}
