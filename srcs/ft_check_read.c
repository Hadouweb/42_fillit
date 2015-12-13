/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 23:11:37 by nle-bret          #+#    #+#             */
/*   Updated: 2015/12/14 00:56:53 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			**ft_generate_tetri(char *buf)
{
	int		y;
	int		x;
	int		i;
	char	**tetri;

	y = 0;
	i = 0;
	if ((tetri = (char **)malloc(4 * sizeof(char *))) == NULL)
		return (NULL);
	while (y < 4)
	{
		if ((tetri[y] = (char *)malloc(5 * sizeof(char))) == NULL)
			return (NULL);
		x = 0;
		while (x < 5)
		{
			tetri[y][x] = buf[i];
			x++;
			i++;
		}
		y++;
	}
	return (tetri);
}

int				ft_is_tetri(char **tetri, int y, int x)
{
	if (x >= 0 && x < 5 && y >= 0 && y < 4)
	{
		if ('#' == tetri[y][x])
		{
			tetri[y][x] = '.';
			return (1
					+ ft_is_tetri(tetri, y + 1, x)
					+ ft_is_tetri(tetri, y - 1, x)
					+ ft_is_tetri(tetri, y, x - 1)
					+ ft_is_tetri(tetri, y, x + 1));
		}
		else
			return (0);
	}
	return (0);
}

int				ft_check_tetri(char *buf)
{
	t_incre	p;
	char	**tetri;

	tetri = ft_generate_tetri(buf);
	p.count = 0;
	p.y = -1;
	while (++p.y < 4)
	{
		p.x = 0;
		while (p.x < 5)
		{
			if (tetri[p.y][p.x] == '#')
			{
				p.count = p.count + ft_is_tetri(tetri, p.y, p.x);
				if (p.count < 4)
					return (0);
			}
			p.x++;
		}
	}
	free(tetri);
	if (p.count == 4)
		return (1);
	else
		return (0);
}

int				ft_check_file(char *buf)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (buf[i])
	{
		k = 0;
		if (!ft_check_tetri(&buf[i]))
			return (0);
		while (k++ < 4)
		{
			j = 0;
			while (buf[j + i] == '.' || buf[j + i] == '#')
				j++;
			if ((j != 4) || (buf[j + i] != '\n'))
				return (0);
			i += j + 1;
		}
		if (buf[i] != '\0')
			i++;
	}
	if (buf[i - 2] != '.' && buf[i - 2] != '#')
		return (0);
	return (1);
}

int				ft_check_all(char *buf)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!ft_check_file(buf))
		return (0);
	while (buf[i])
	{
		if (i == 0)
			i += 20;
		else
			i += 21;
		if (buf[i] || i == 20)
			count++;
	}
	if (count > 0 && count < 26)
		return (1);
	return (0);
}
