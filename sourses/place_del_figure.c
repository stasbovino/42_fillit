/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_del_figure.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 22:19:36 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/03/28 18:35:53 by gwyman-m         ###   ########.fr       */
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

int			map_restore(t_square *dst, char *opt, int i)
{
	static t_square **tmp = NULL;
	static int		count;
	static char		*eq = NULL;
	char			*check;

	if (!tmp)
	{
		if (opt)
			if (!(eq = ft_strdup(opt)))
				return (-1);
		return (mapr_opt_init(&tmp, &count, i));
	}
	if (ft_strcmp(opt, "clean") == 0)
		return (mapr_opt_clean(tmp, eq, count));
	if (eq)
		if ((check = ft_strchr(eq, (char)(i + 65))))
		{
			if (ft_strcmp(opt, "rest") == 0)
				return (mapr_opt_rest(tmp, dst, check));
			else if (ft_strcmp(opt, "save") == 0)
				return (mapr_opt_save(tmp, dst, i));
		}
	return (0);
}
