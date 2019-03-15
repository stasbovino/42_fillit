/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:17:29 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/03/15 14:17:32 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef struct		s_coordinates
{
	int				x;
	int				y;
}					t_coordinates;

typedef struct		s_typeof_figure
{
	t_coordinates	first;
	t_coordinates	second;
	t_coordinates	third;
	t_coordinates	fourth;
}					t_typeof_figure;

typedef struct		s_figure
{
	char			order;
	t_typeof_figure	fig;
}					t_figure;

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
