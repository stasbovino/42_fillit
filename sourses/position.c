/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 21:32:46 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/03/18 21:36:14 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int				check_borders(int size, int x, int y)
{
	if (x < size && y < size && x >= 0 && y >= 0)
		return (1);
	else
		return (0);
}

int				is_figure_fit(t_square *src, t_figure *figure, int x, int y)
{
	char		**map;

	map = src->map;
	if (check_borders(src->size, y + figure->fig.second.y,
				x + figure->fig.second.x))
		if (!(ft_isupper(map[y + figure->fig.second.y]
						[x + figure->fig.second.x])))
			if (check_borders(src->size, y + figure->fig.third.y,
						x + figure->fig.third.x))
				if (!(ft_isupper(map[y + figure->fig.third.y]
								[x + figure->fig.third.x])))
					if (check_borders(src->size, y + figure->fig.fourth.y,
								x + figure->fig.fourth.x))
						if (!(ft_isupper(map[y + figure->fig.fourth.y]
								[x + figure->fig.fourth.x])))
							return (1);
	return (-1);
}

t_coord			*first_diag(t_square *src, t_figure *figure, int k, int worth)
{
	int			i;
	int			x;
	int			y;

	i = -1;
	while (++i < (k / 2 + 1))
	{
		x = i;
		y = 0;
		while (x >= 0 && y <= i)
		{
			if (!(ft_isupper((src->map)[y][x])))
				if (x + y <= worth)
					if (is_figure_fit(src, figure, x, y) == 1)
					{
						worth = x + y;
						return (ft_create_coords(x, y));
					}
			x--;
			y++;
		}
	}
	return (NULL);
}

t_coord			*second_diag(t_square *src, t_figure *figure, int k, int worth)
{
	int			i;
	int			x;
	int			y;

	i = -1;
	while (++i < (k / 2))
	{
		x = src->size - 1;
		y = i + 1;
		while (x >= (src->size - 1 - y) && y <= src->size - 1)
		{
			if (!(ft_isupper((src->map)[y][x])))
				if (x + y < worth)
					if (is_figure_fit(src, figure, x, y) == 1)
					{
						worth = x + y;
						return (ft_create_coords(x, y));
					}
			x--;
			y++;
		}
	}
	return (NULL);
}

t_coord			*find_pos(t_square *src, t_figure *figure)
{
	t_coord		*a;
	int			k;
	int			worth;

	k = 2 * src->size - 2;
	worth = (src->size - 1) * 2;
	if (!(a = first_diag(src, figure, k, worth)))
		if (!(a = second_diag(src, figure, k, worth)))
			return (NULL);
	return (a);
	return (NULL);
}
