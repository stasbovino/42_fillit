/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 21:37:38 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/03/27 17:43:45 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int				fill_it(t_square **map, t_figure **figures, int count, int i)
{
	t_coord		*pos;
	t_square	*tmp;
	int			ret;

	if (!(tmp = copy_map(*map, 1)))
		return (-2);
//	printf("~~ FIGURE IS %c ~~\n", i + 65);
	if (i < count)
	{
		while ((pos = find_pos(tmp, figures[i])))
		{
			place_figure(tmp, figures[i], pos);
//			printf("\n	NEW PLACE FOR %c:\n", i + 65);
//			print_map(tmp);
//			ft_putchar('\n');
			if ((ret = fill_it(&tmp, figures, count, i + 1)) < 0)
			{
//				printf("\n~~ FIGURE IS %c ~~\n", i + 65);
				del_figure(tmp, figures[i], pos);
//				printf("Deleted %c\n", i + 65);
//				print_map(tmp);
//				ft_putchar('\n');
				map_restore(tmp, "rest", i);
				free(pos);
				if (ret == -2)
					return (-2);
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
//		printf("NET MESTA FOR %c\n\n", i + 65);
		map_restore(tmp, "save", i);
		clean_map(tmp);
		return (-1);
	}
	clean_map(tmp);
	return (0);
}

/*void			check_equals(t_square **map, int count, int i)
{
	static char		*equal_fig = NULL;
	static t_square	tmp[26];

	if (!equal_fig)
		equal_fig = find_same_figures(a, count);
	if (ft_countchars(equal_fig, i + 65) != 1)
		return ;
	tmp[i] = 
}
*/

int				get_solution(t_figure **a, int count, int size)
{
	t_square	*map;
	int			ret;
	char		*equal_fig;
	int			i;

	equal_fig = find_same_figures(a, count);
	i = -1;
	map_restore(NULL, equal_fig, count);
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
