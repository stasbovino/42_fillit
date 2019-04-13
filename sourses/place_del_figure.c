/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_del_figure.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 22:19:36 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/04/13 19:41:27 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		place_figure(t_square *dst, t_figure *figure, t_coord *pos)
{
	char			s;
	char			***map;
	char			c;

	map = &(dst->map);
	s = figure->order;
	(*map)[pos->y][pos->x] = s;
	if ((*map)[pos->y + figure->fig.second.y]
			[pos->x + figure->fig.second.x] == '!')
		c = s + 32;
	else
		c = s;
	(*map)[pos->y + figure->fig.second.y][pos->x + figure->fig.second.x] = c;
	if ((*map)[pos->y + figure->fig.third.y]
			[pos->x + figure->fig.third.x] == '!')
		c = s + 32;
	else
		c = s;
	(*map)[pos->y + figure->fig.third.y][pos->x + figure->fig.third.x] = c;
	if ((*map)[pos->y + figure->fig.fourth.y]
			[pos->x + figure->fig.fourth.x] == '!')
		c = s + 32;
	else
		c = s;
	(*map)[pos->y + figure->fig.fourth.y][pos->x + figure->fig.fourth.x] = c;
}

void		del_figure(t_square *dst, t_figure *figure, t_coord *pos)
{
	char		***map;
	char		c;

	map = &(dst->map);
	(*map)[pos->y][pos->x] = '!';
	if (ft_islower((*map)[pos->y + figure->fig.second.y]
				[pos->x + figure->fig.second.x]))
		c = '!';
	else
		c = '.';
	(*map)[pos->y + figure->fig.second.y][pos->x + figure->fig.second.x] = c;
	if (ft_islower((*map)[pos->y + figure->fig.third.y]
				[pos->x + figure->fig.third.x]))
		c = '!';
	else
		c = '.';
	(*map)[pos->y + figure->fig.third.y][pos->x + figure->fig.third.x] = c;
	if (ft_islower((*map)[pos->y + figure->fig.fourth.y]
				[pos->x + figure->fig.fourth.x]))
		c = '!';
	else
		c = '.';
	(*map)[pos->y + figure->fig.fourth.y]
		[pos->x + figure->fig.fourth.x] = c;
}
