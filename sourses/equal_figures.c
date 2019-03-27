/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal_figures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 21:45:22 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/03/27 17:23:56 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				compare_figures(t_figure *a, t_figure *b)
{
	if ((a->fig.second.x == b->fig.second.x) &&
			(a->fig.second.y == b->fig.second.y))
		if ((a->fig.third.x == b->fig.third.x) &&
				(a->fig.third.y == b->fig.third.y))
			if ((a->fig.fourth.x == b->fig.fourth.x) &&
					(a->fig.fourth.y == b->fig.fourth.y))
				return (1);
	return (-1);
}

char			*clear_str_from_single_figures(char *a)
{
	int		i;
	char	*b;

	i = -1;
	while (a[++i])
		if (ft_isupper(a[i]))
		{
			if (a[i + 1])
				if (!(ft_isupper(a[i + 1])))
					if (i - 1 >= 0 && !(ft_isupper(a[i - 1])))
						a[i] = ' ';
		}
		else
			a[i] = ' ';
	b = ft_strtrim_all(a);
	if (b)
		if (ft_strlen(b) == 1)
		{
			free(b);
			b = NULL;
		}
	if (a)
		free(a);
	return (b);
}

char			*find_same_figures(t_figure **a, int count)
{
	char	*list;
	int		i;
	int		k;
	int		j;

	if (!(list = ft_strnew(count * 2 - 1)))
		return (NULL);
	i = -1;
	k = 0;
	while (++i < count)
	{
		if (ft_countchars(list, a[i]->order) == 1)
			continue;
		list[k++] = a[i]->order;
		j = -1;
		while (++j < count)
		{
			if (j == i)
				continue;
			else if (compare_figures(a[i], a[j]) == 1)
			{
				list[k++] = a[j]->order;
			}
		}
		list[k++] = ' ';
	}
	list[k] = '\0';
	list = clear_str_from_single_figures(list);
	return (list);
}
