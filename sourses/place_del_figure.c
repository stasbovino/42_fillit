/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_del_figure.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 22:19:36 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/03/27 19:24:52 by gwyman-m         ###   ########.fr       */
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

void		restoration(t_square *dst, t_square *src)
{
	int		x;
	int		y;
	int		n;

	n = src->size;
	y = -1;
	while (++y < n)
	{
		x = -1;
		while (++x < n)
			if ((src->map)[y][x] == '!')
				(dst->map)[y][x] = '!';
	}
}

int			map_restore(t_square *dst, char *opt, int i)
{
	static t_square **tmp = NULL;
	static int		count;
	int				k;
	static char		*eq = NULL;
	char			*check;
	int				last;

	if (!tmp)
	{
		count = i;
		if (opt)
			if (!(eq = ft_strdup(opt)))
				return (-1);
		k = -1;
		tmp = (t_square**)malloc(sizeof(t_square*) * count);
		while (++k < count)
			tmp[k] = NULL;
		return (0);
	}
	if (!eq)
		return (0);
	if (ft_strcmp(opt, "clean") == 0)
	{
		k = -1;
		while (++k < count)
			clean_map(tmp[k]);
		free(tmp);
		free(eq);
	}
	if ((check = ft_strchr(eq, (char)(i + 65))))
		{
			if (ft_strcmp("rest", opt) == 0)
			{
				if (!(check[1]))
					return (0);
				if (!(ft_isupper(check[1])))
					return (0);
				last = check[1] - 65;
				if (!tmp[last] || tmp[last]->size != dst->size)
					return (0);
			}
		}
	else
		return (0);
	if (ft_strcmp(opt, "save") == 0)
	{
		clean_map(tmp[i]);
		tmp[i] = copy_map(dst, 0);
	}
	else if (ft_strcmp(opt, "rest") == 0)
		restoration(dst, tmp[last]);
	return (0);
}
