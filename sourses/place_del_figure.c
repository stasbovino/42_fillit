/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_del_figure.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 22:19:36 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/03/27 17:43:07 by gwyman-m         ###   ########.fr       */
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
//	printf("%d\n", s);
//	printf("figure is:\n%d.%d\n%d.%d\n%d.%d\n%d.%d\ns is %c\n", figure->fig.first.x, figure->fig.first.y, figure->fig.second.x, figure->fig.second.y, figure->fig.third.x, figure->fig.third.y, figure->fig.fourth.x, figure->fig.fourth.y, s);
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
			{
				(dst->map)[y][x] = '!';
	//			printf("placed\n");
			}
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
		{
			tmp[k] = NULL;
//			printf("%d nulled\n", k);
		}
//		printf("%s\n", eq);
		return (0);
	}
//	printf("eq is !%s!\n%c\n",eq, i + 65);
	if (!eq)
	{
//		printf("eq nulled\n");
		return (0);
	}
	if ((k = ft_countchars(eq, (char)(i + 65))) != 1)
	{
//		printf(" ne nashel: k is %d\n", k);
		return (0);
	}
	else if (ft_strcmp("rest", opt) == 0)
		if ((check = ft_strchr(eq, (char)(i + 65))))
	{
//		printf("check is %s\n", check);
		if (!(check[1]))
			return (0);
//		printf("check[1] is %c\n", check[1]);
		if (!(ft_isupper(check[1])))
			return (0);
		last = check[1] - 65;
//		printf("last is %d\n", last);
		if (!tmp[last] || tmp[last]->size != dst->size)
			return (0);
	}
//	printf("eq is %s\nest' i ne last: k is %d, opt %s\n", eq, k, opt);
//	printf("");
	if (ft_strcmp(opt, "save") == 0)
	{
//		if (tmp[i])
//			clean_map(tmp[i]);
//		printf("\x1b[1;31m	SAVED: FIG %c\n\x1b[0m", last + 65);
		tmp[i] = copy_map(dst, 0);
	}
	else if (ft_strcmp(opt, "rest") == 0)
	{
//		print_map(tmp[last]);
		restoration(dst, tmp[last]);
//		printf("\x1b[1;32m	RESTORED: FIG %c FROM FIG %c\n\x1b[0m", i + 65, last + 65);
//		printf("	after:\n");
//		print_map(dst);
//		printf("\n	from:\n");
//		print_map(tmp[last]);
//		if (tmp[i])
//			clean_map(tmp[i]);
	}
	else if (ft_strcmp(opt, "clean") == 0)
	{
		k = -1;
		while (++k < count)
			free(tmp[k]);
		free(tmp);
	}
		return (0);
}
