/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 02:54:12 by nle-bret          #+#    #+#             */
/*   Updated: 2015/12/07 22:04:40 by hdebard          ###   ########.fr       */
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
	if (tetri[y][x] == '#' &&
			!((x < 4 && tetri[y][x + 1] == '#')
				|| (x > 0 && tetri[y][x - 1] == '#')
				|| (y < 3 && tetri[y + 1][x] == '#')
				|| (y > 0 && tetri[y - 1][x] == '#')))
		return (0);
	return (1);
}

int				ft_check_tetri(char *buf)
{
	t_incre	p;
	t_pos	*pos;
	char	**tetri;

	pos = ft_save_pos(buf);
	tetri = ft_generate_tetri(buf);
	p.count = 0;
	p.y = -1;
	while (++p.y < 4)
	{
		p.x = 0;
		while (p.x < 5)
		{
			if (!ft_is_tetri(tetri, p.y, p.x))
				return (0);
			else if (tetri[p.y][p.x] == '#')
				p.count++;
			p.x++;
		}
	}
	if (p.count != 4)
		return (0);
	free(tetri);
	free(pos);
	return (1);
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
	count = -1;
	if (!ft_check_file(buf))
		return (0);
	while (buf[i])
	{
		i += 21;
		count++;
	}
	if (count > 0 && count < 27)
		return (1);
	return (0);
}
