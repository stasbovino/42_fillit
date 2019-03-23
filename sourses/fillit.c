/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 21:37:38 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/03/23 20:35:12 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				fill_it(t_square **map, t_figure **figures, int count, int i)
{
	static int k;
	t_coord		*pos;
	t_square	*tmp;

	tmp = copy_map(*map);
	if (i < count)
	{
		printf("i is %d k is %d\n", i, k);
		while ((pos = find_pos(tmp, figures[i])))
		{
			place_figure(tmp, figures[i], pos);
			k++;
	//		printf("i is %d k is %d\n", i, k);
			print_map(tmp);
			if (fill_it(&tmp, figures, count, i + 1) != 1)
				delete_figure(tmp, figures[i], pos);
	//		printf("deleted %d %c\n", i, (tmp->map)[pos->y][pos->x]);
	//		print_map(tmp);
			if (k == count)
				return (1);
		}
		printf("ne vlezla\n");
		k--;
		return (-1);
	}
	return (-1);
}

int				test(t_figure **a, int count, int size)
{
	t_square	*map;
	int			i;

	i = 0;
//	size = count * 4;
	if (!(map = create_map(size)))
	{
//		printf("ne sozdal\n");
		return (0);
	}
//	printf("map is:\n");
//	print_map(map);
//	printf("end\n");
/*	while (i < count)
	{
//		printf("posfind\n");
		if (!(pos = find_pos(map, a[i])))
		{
		//	printf("blya\n");
			break;
		}
		else
		{
//			printf("figure is %d of %d\npos is %d.%d\n", i + 1, count, pos->x, pos->y);
			place_figure(map, a[i], pos);
//			print_map(map);
			free(pos);
			i++;
		}
	}*/
	printf("%d\n", size);
	print_map(map);
	fill_it(&map, a, count, 0);
/*	while (fill_it(&map, a, count, 0) != 1)
	{
		clean_map(map);
		map = create_map(size++);
	}*/
	print_map(map);
	clean_map(map);
	return (0);
}
