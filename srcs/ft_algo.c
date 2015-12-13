/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 23:11:07 by nle-bret          #+#    #+#             */
/*   Updated: 2015/12/13 23:11:17 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_calcul_tetri(t_tetri **list)
{
	char	**map;
	double	tmp;
	int		size;
	t_pos	p;
	t_nb	nb;

	nb.nb_list = ft_count_tetri(*list);
	tmp = ft_sqrt(nb.nb_list * 4);
	size = tmp;
	if (tmp - size > 0.0)
		size++;
	map = ft_generate_map(size);
	nb.max = ft_strlen(map[0]);
	p.y = 0;
	p.x = 0;
	while (ft_place_tetri(*list, map, p, nb) == 0)
	{
		free(map);
		size++;
		map = ft_generate_map(size);
		nb.max = ft_strlen(map[0]);
	}
	ft_print_map(map);
	ft_clean_memory(list, map);
}

int		ft_place_tetri(t_tetri *list, char **map, t_pos p, t_nb nb)
{
	p.y = 0;
	if (((list->n) - 65) > (nb.nb_list / 2))
	{
		if (ft_heuristic(list, map, nb.max) == 0)
			return (0);
	}
	while (map[p.y])
	{
		p.x = 0;
		while (map[p.y][p.x])
		{
			if (list && ft_verify_tetri(list, map, p, nb.max))
			{
				ft_add_char(list, map, p);
				if (list->next == NULL)
					return (1);
				if (ft_place_tetri(list->next, map, p, nb))
					return (1);
				ft_remove_list(list->pos, map, p);
			}
			p.x++;
		}
		p.y++;
	}
	return (0);
}
