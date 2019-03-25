/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 21:37:38 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/03/25 21:45:38 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int				fill_it(t_square **map, t_figure **figures, int count, int i)
{
	t_coord		*pos;
	t_square	*tmp;
	int			ret;

	if (!(tmp = copy_map(*map)))
		return (-2);
//	printf("~~ FIGURE IS %d ~~\n", i);
	if (i < count)
	{
		while ((pos = find_pos(tmp, figures[i])))
		{
			place_figure(tmp, figures[i], pos);
//			print_map(tmp);
//			ft_putchar('\n');
			if ((ret = fill_it(&tmp, figures, count, i + 1)) < 0)
			{
				del_figure(tmp, figures[i], pos);
				free(pos);
				if (ret == -2)
					return (-2);
//				printf("Не смог подставить\n");
//				print_map(tmp);
//				ft_putchar('\n');
			}
			else
			{
				free(pos);
				if (ret == 0)
					print_map(tmp);
				clean_map(tmp);
				return (1);
			}
		}
		clean_map(tmp);
		return (-1);
	}
	clean_map(tmp);
	return (0);
}

int				get_solution(t_figure **a, int count, int size)
{
	t_square	*map;
	int			ret;

	if (!(map = create_map(size)))
		return (-1);
	while ((ret = fill_it(&map, a, count, 0)) != 1)
	{
		clean_map(map);
		if (ret == -2)
			return (-1);
		if (!(map = create_map(size++)))
			return (-1);
	}
	clean_map(map);
	return (0);
}
