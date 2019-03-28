/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 21:37:38 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/03/28 19:37:51 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				clean_and_ret(t_square *tmp, int ret)
{
	clean_map(tmp);
	return (ret);
}

int				place_it(t_square *tmp, t_figure **figures, int count, int i)
{
	t_coord	*pos;
	int		ret;

	while ((pos = find_pos(tmp, figures[i])))
	{
		place_figure(tmp, figures[i], pos);
		if ((ret = fill_it(&tmp, figures, count, i + 1)) < 0)
		{
			if (ret == -2)
				return (clean_and_ret(tmp, -2));
			del_figure(tmp, figures[i], pos);
			map_restore(tmp, "rest", i);
			free(pos);
		}
		else
		{
			free(pos);
			if (ret == 0)
				print_map(tmp);
			return (clean_and_ret(tmp, 1));
		}
	}
	return (3);
}

int				fill_it(t_square **map, t_figure **figures, int count, int i)
{
	t_square	*tmp;
	int			ret;

	if (i >= count)
		return (0);
	if (!(tmp = copy_map(*map, 1)))
		return (-2);
	if ((ret = place_it(tmp, figures, count, i)) != 3)
		return (ret);
	map_restore(tmp, "save", i);
	clean_map(tmp);
	return (-1);
}

int				get_solution(t_figure **a, int count, int size)
{
	t_square	*map;
	int			ret;
	char		*equal_fig;

	equal_fig = find_same_figures(a, count);
	if (map_restore(NULL, equal_fig, count) == -1)
		return (-1);
	free(equal_fig);
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
	map_restore(NULL, "clean", count);
	clean_map(map);
	return (0);
}
