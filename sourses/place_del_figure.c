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
#include <stdio.h>

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

int			mapr_opt_solut(t_square *dst, char *eq)
{
	int			n;
	int			i;
	int			j;
	char		**tab;
	int			k;
	char		*order;

	if (!eq)
	{
		print_map(dst);
		return (0);
	}
	n = dst->size;
	tab = dst->map;
	k = -1;
//	printf("eq is %s\n", eq);
	if (!(order = ft_strnew(26)))
		return (-1);
	i = -1;
	while (++i < n)
	{
		j = 0;
		while (tab[i][j])
		{
			if (ft_islower(tab[i][j]))
				if (!ft_strchr(order, tab[i][j] - 32))
					order[++k] = tab[i][j] - 32;
			if (ft_isupper(tab[i][j]))
				if (!ft_strchr(order, tab[i][j]))
					order[++k] = tab[i][j];
			j++;
		}
	}
//	printf("order is %s\n\n", order);
//	print_map(dst);
//	printf("\nswaping:\n");
	while (1)
	{
		i = -1;
		j = -1;
		while (eq[++i])
		{
			if (eq[i] == ' ')
			{
				j = -1;
				continue ;
			}
			while (order[++j])
				if (order[j] == eq[i])
				{
//					printf("%c\n", order[j]);
					break ;
				}
			if (!order[j])
				break ;
		}
		if (!eq[i])
		{
//			printf("order is correct!!\n\n");
			print_map(dst);
			break ;
		}
		else
		{
//			printf("cause of %c and %c ", eq[i], eq[i - 1]);
//			printf("order is not correct\n\n");
			j = -1;
			while (++j < n)
				ft_strchr_swap(&tab[j], eq[i], eq[i - 1]);
			ft_strchr_swap(&order, eq[i], eq[i - 1]);
//			printf("order is %s now\n", order);
//			print_map(dst);
		}
	}
	free(order);
	return (1);
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
//	printf("eq is %s\n", eq);
//	printf("search for %c\n", i + 65);
	check = NULL;
	if (ft_strcmp(opt, "finish") == 0)
		return (mapr_opt_solut(dst, eq));
	if (ft_strcmp(opt, "clean") == 0)
		return (mapr_opt_clean(tmp, eq, count));
	if (eq)
		if (ft_strchr(eq, (char)(i + 65)))
			if (ft_strcpy_whilech(&check, eq, (char)(i + 65)))
			{
	//			printf("letter is %c, eq is %s, check is %s, opt is %s\n", i + 65, eq, check, opt);
				if (ft_strcmp(opt, "rest") == 0)
				{
					return (mapr_opt_rest(tmp, dst, &check));
				}
				else if (ft_strcmp(opt, "save") == 0)
				{
					free(check);
					return (mapr_opt_save(tmp, dst, i));
				}
			}
	return (0);
}
