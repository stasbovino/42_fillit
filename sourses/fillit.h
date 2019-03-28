/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:17:29 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/03/28 19:38:10 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"

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

typedef struct		s_square
{
	char	**map;
	int		size;
}					t_square;

int					fill_it(t_square **map, t_figure **figures,
		int count, int i);
int					mapr_opt_rest(t_square **tmp, t_square *dst, char *check);
int					mapr_opt_clean(t_square **tmp, char *eq, int count);
int					mapr_opt_init(t_square ***tmp, int *count, int i);
int					mapr_opt_save(t_square **tmp, t_square *dst, int i);
int					map_restore(t_square *dst, char *opt, int i);
char				*clear_str_from_single_figures(char *a);
char				*find_same_figures(t_figure **a, int count);
int					compare_figures(t_figure *a, t_figure *b);
void				print_usage(void);
void				print_error(int fd, t_figure **a, int count);
void				clean_them_all(t_figure **a, int count);
int					get_solution(t_figure **a, int count, int size);
void				del_figure(t_square *dst, t_figure *figure, t_coord *pos);
void				place_figure(t_square *dst, t_figure *figure, t_coord *pos);
t_coord				*find_pos(t_square *src, t_figure *figure);
t_square			*create_map(int count);
void				print_map(t_square *map);
int					clean_map(t_square *map);
t_square			*copy_map(t_square *src, int opt);
t_figure			*read_figure(int fd, int n);
int					check_line(char *tmp);
int					valid_line(char *line);
int					get_figure(char *line, int n, t_figure **place);

#endif
