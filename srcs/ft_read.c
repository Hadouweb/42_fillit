/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 06:28:55 by nle-bret          #+#    #+#             */
/*   Updated: 2015/12/14 00:00:44 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_pos	*ft_format_pos(t_pos *pos)
{
	int		i;
	int		tmp;

	i = 0;
	tmp = 0;
	if (pos[0].y != 0)
	{
		tmp = pos[0].y;
		while (i < 4)
			pos[i++].y -= tmp;
	}
	i = 0;
	if (pos[0].x != 0)
	{
		tmp = pos[0].x;
		while (i < 4)
			pos[i++].x -= tmp;
	}
	return (pos);
}

t_pos	*ft_save_pos(char *tetri)
{
	int		y;
	int		x;
	int		p;
	int		i;
	t_pos	*pos;

	y = 0;
	p = 0;
	i = 0;
	if ((pos = (t_pos *)malloc(20 * sizeof(t_pos))) == NULL)
		return (NULL);
	while (y++ < 4)
	{
		x = 0;
		while (x++ < 5)
		{
			if (tetri[i] == '#')
			{
				pos[p].y = y;
				pos[p++].x = x;
			}
			i++;
		}
	}
	return (ft_format_pos(pos));
}

void	ft_save_tetri(char *buf)
{
	t_tetri	*list;
	t_pos	*pos;
	size_t	i;
	char	n;

	i = 0;
	list = NULL;
	n = 'A';
	if (ft_check_all(buf) == 1)
	{
		while (i < ft_strlen(buf))
		{
			pos = ft_save_pos(&buf[i]);
			ft_tpush_back(&list, pos, n);
			n++;
			i += 21;
		}
		ft_calcul_tetri(&list);
	}
	else
		ft_print_error();
}

void	ft_read_file(char *name)
{
	int		fd;
	int		ret;
	char	buf[4096];
	int		i;

	i = 0;
	if ((fd = open(name, O_RDONLY)) == -1)
		ft_print_error();
	if ((ret = read(fd, buf, 4096)) == -1)
		ft_print_error();
	buf[ret] = '\0';
	ft_save_tetri(buf);
	if (close(fd) == -1)
		ft_print_error();
}
