/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 07:37:29 by nle-bret          #+#    #+#             */
/*   Updated: 2015/12/14 00:00:10 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"

typedef struct		s_pos
{
	int				y;
	int				x;
}					t_pos;

typedef struct		s_incre
{
	int				y;
	int				x;
	int				count;
}					t_incre;

typedef struct		s_nb
{
	int				nb_list;
	int				max;
}					t_nb;

typedef struct		s_tetri
{
	struct s_tetri	*next;
	t_pos			*pos;
	char			n;
}					t_tetri;

t_tetri				*ft_create_elem(t_pos *pos, char n);
void				ft_tpush_back(t_tetri **l, t_pos *pos, char n);

void				ft_read_file(char *name);
void				ft_save_tetri(char *buf);
t_pos				*ft_save_pos(char *tetri);
t_pos				*ft_format_pos(t_pos *pos);

void				ft_calcul_tetri(t_tetri **list);
int					ft_place_tetri(t_tetri *list, char **map, t_pos p, t_nb nb);

char				**ft_generate_map(int max);
void				ft_clean_memory(t_tetri **list, char **map);

void				ft_print_map(char **map);
void				ft_print_pos(t_pos *pos);
void				ft_print_error(void);

void				ft_add_char(t_tetri *list, char **map, t_pos p);
int					ft_verify_tetri(t_tetri *list, char **map, t_pos p,
									int max);
void				ft_remove_list(t_pos *pos, char **map, t_pos p);
int					ft_count_tetri(t_tetri *list);
double				ft_sqrt(double nb);

int					ft_heuristic(t_tetri *list, char **map, int max);
int					ft_space_counter(char **map, int max);
void				ft_clean(char **map);
int					ft_contaminate(char **map, int x, int y, int max);

int					ft_check_file(char *buf);
int					ft_check_tetri(char *buf);
int					ft_is_tetri(char **tetri, int y, int x);
char				**ft_generate_tetri(char *buf);
int					ft_check_all(char *buf);

#endif
