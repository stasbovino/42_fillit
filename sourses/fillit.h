/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:17:29 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/03/17 21:34:38 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "libft.h"

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_typeof_figure
{
	t_coord			first;
	t_coord			second;
	t_coord			third;
	t_coord			fourth;
}					t_typeof_figure;

typedef struct		s_figure
{
	char			order;
	t_typeof_figure	fig;
}					t_figure;

int					test(t_figure **a);

void				place_figure(int size, char ***map, t_figure *figure, t_coord *pos);
t_coord				*find_pos(int size, char **map, t_figure *figure);
char				**create_map(int *size_back, int count);
void				print_map(int size, char **map);
int					clean_map(int size, char **map);
char				**copy_map(int size, char **src);

int					count_figures(int fd);/*fillit.c*/
int					clean_them_all(t_figure **a, int count);

int					end_reading(int fd);/*read_figure.c*/
int					read_one_line(int fd, char **line);
t_figure			*read_figure(int fd, int n);

int					check_line(char *tmp);/*check_valid.c*/
int					find_sharps(char **line, int i, int opt);
int					valid_line(char *line);

int					write_coord(int *x, int *y, char *line, int opt);/*get_figure.c*/
int					get_figure(char *line, int n, t_figure **place);

#endif
