/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 21:32:46 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/03/26 22:31:31 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int					check_borders(int size, int x, int y)
{
	if (x < size && y < size && x >= 0 && y >= 0)
		return (1);
	else
		return (0);
}

int					is_figure_fit(t_square *src, t_figure *figure, int x, int y)
{
	char			**map;

	map = src->map;
	if (check_borders(src->size, y + figure->fig.second.y,
				x + figure->fig.second.x))
		if (!(ft_isalpha(map[y + figure->fig.second.y]
						[x + figure->fig.second.x])))
			if (check_borders(src->size, y + figure->fig.third.y,
						x + figure->fig.third.x))
				if (!(ft_isalpha(map[y + figure->fig.third.y]
								[x + figure->fig.third.x])))
					if (check_borders(src->size, y + figure->fig.fourth.y,
								x + figure->fig.fourth.x))
						if (!(ft_isalpha(map[y + figure->fig.fourth.y]
								[x + figure->fig.fourth.x])))
							return (1);
	return (-1);
}

t_coord				*find_place(t_square *src, t_figure *figure)
{
	int				x;
	int				y;
	int				size;

	size = src->size;
	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
			if ((src->map)[y][x] == '.')
				if (is_figure_fit(src, figure, x, y) == 1)
					return (ft_create_coords(x, y));
	}
	return (NULL);
}

t_coord				*find_pos(t_square *src, t_figure *figure)
{
	t_coord			*a;

	if (!(a = find_place(src, figure)))
		return (NULL);
	(src->map)[a->y][a->x] = '!';
	return (a);
}
