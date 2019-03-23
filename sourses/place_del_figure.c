/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_del_figure.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 22:19:36 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/03/23 22:21:46 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			place_figure(t_square *dst, t_figure *figure, t_coord *pos)
{
	int			i;
	char		s;
	char		***map;

	map = &(dst->map);
	s = figure->order;
	i = 0;
	(*map)[pos->y][pos->x] = s;
	(*map)[pos->y + figure->fig.second.y][pos->x + figure->fig.second.x] = s;
	(*map)[pos->y + figure->fig.third.y][pos->x + figure->fig.third.x] = s;
	(*map)[pos->y + figure->fig.fourth.y][pos->x + figure->fig.fourth.x] = s;
}

void			del_figure(t_square *dst, t_figure *figure, t_coord *pos)
{
	int			i;
	char		s;
	char		***map;

	map = &(dst->map);
	s = figure->order;
	i = 0;
	(*map)[pos->y][pos->x] = '!';
	(*map)[pos->y + figure->fig.second.y][pos->x + figure->fig.second.x] = '.';
	(*map)[pos->y + figure->fig.third.y][pos->x + figure->fig.third.x] = '.';
	(*map)[pos->y + figure->fig.fourth.y][pos->x + figure->fig.fourth.x] = '.';
}
