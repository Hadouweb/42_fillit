/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 03:59:13 by nle-bret          #+#    #+#             */
/*   Updated: 2015/12/07 21:50:58 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_generate_map(int max)
{
	int		l;
	int		c;
	char	**map;

	l = 0;
	if ((map = (char **)malloc(max * sizeof(char *) + 1)) == NULL)
		return (NULL);
	while (l < max)
	{
		if ((map[l] = (char *)malloc(max * sizeof(char) + 1)) == NULL)
			return (NULL);
		c = 0;
		while (c < max)
		{
			map[l][c] = '.';
			c++;
		}
		map[l][c] = '\0';
		l++;
	}
	map[l] = 0;
	return (map);
}

void	ft_clean_memory(t_tetri **list, char **map)
{
	t_tetri		*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->pos);
		(*list)->pos = NULL;
		free(*list);
		*list = NULL;
		*list = tmp;
	}
	if (map)
		free(map);
	map = NULL;
}
