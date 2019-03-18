/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 21:37:38 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/03/18 21:37:50 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*
int			fill_it(t_figure **figures, int count)
{
	char	**map;
	char	**thebest

	if (create_map(&map, count * 4) != 1)
		return (-1);
}*/

int				test(t_figure **a, int count)
{
	t_square	*map;
	t_square	*map2;
	int			size;
	int			sqrt;
	t_coord		*pos;
	int			i;

	i = 0;
	size = count * 4;
	if (!(map = create_map(size)))
	{
		printf("ne sozdal\n");
		return (0);
	}
	printf("map is:\n");
	print_map(map);
	print_map(map2);
	pos->x = 0;
	pos->y = 0;
	while (i < count)
	{
		if (!(pos = find_pos(map, a[i])))
		{
			printf("blya\n");
			break;
		}
		else
		{
			printf("figure is %d of %d\npos is %d.%d\n", i, count, pos->x, pos->y);
			place_figure(map, a[i], pos);
			print_map(map);
			i++;
		}
	}
	return (0);
}

