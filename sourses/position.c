/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 21:32:46 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/03/23 21:44:26 by gwyman-m         ###   ########.fr       */
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

int		is_free(int c)
{
	if (c == '.')
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

/*t_coord			*first_diag(t_square *src, t_figure *figure, int k, int worth)
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
	//		printf("x is %d y is %d = %c\n", x, y, (src->map)[y][x]);
			if ((is_free((src->map)[y][x])))
				if (x + y <= worth)
					if (is_figure_fit(src, figure, x, y) == 1)
					{
	//					printf("x is %d y is %d = %c\n", x, y, (src->map)[y][x]);
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
			if ((is_free((src->map)[y][x])))
				if (x + y < worth)
					if (is_figure_fit(src, figure, x, y) == 1)
					{
	//					printf("x is %d y is %d = %c\n", x, y, (src->map)[y][x]);
						worth = x + y;
						return (ft_create_coords(x, y));
					}
			x--;
			y++;
		}
	}
	return (NULL);
} */

t_coord			*find_place(t_square *src, t_figure *figure)
{
	int			i;
	int			x;
	int			y;
	int			size;

	size = src->size;
	i = -1;
	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			if ((is_free((src->map)[y][x])))
				if (is_figure_fit(src, figure, x, y) == 1)
				{
	//				printf("x is %d y is %d = %c\n", x, y, (src->map)[y][x]);
					return (ft_create_coords(x, y));
				}
		}
	}
	return (NULL);
}


/*
 *	search the free position for figure on map
 *	worth of position is a sum of it (x + y)
 *	
 *	we are interested in placing figure on position
 *	that has the best sum of coord
 *	
 *	figures with the same sum of coord are placed on
 *	one diagonal, so functions first_diag and second_diag
 *	searching the best and free place on first half of map and
 *	second half respectively
 *
 *	first half is:			second half is:
 *	. . . .
 *	. . .							.
 *	. .							  . .
 *	.							. . .
 */

t_coord				*find_pos(t_square *src, t_figure *figure)
{
	t_coord			*a;
	int				k;
	int				worth;

	k = 2 * src->size - 2;
	worth = (src->size - 1) * 2;
	if (!(a = find_place(src, figure)))
	{
	//	printf("net\n");
			return (NULL);
	}
	(src->map)[a->y][a->x] = '!';
	return (a);
}
