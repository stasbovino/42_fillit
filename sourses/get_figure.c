/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_figure.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:01:47 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/03/27 19:26:03 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static int		write_coord(int *x, int *y, char *line, int opt)
{
	static int i;
	static int start;

	if (opt == 1)
	{
		i = 0;
		i = ft_strchrpos(line, '#');
		start = i;
		i++;
	}
	while (line[i] && (line[i] != '#'))
		i++;
	if (line[i] == '#')
	{
		*x = (i % 4) - (start % 4);
		*y = (i / 4) - (start / 4);
		i++;
	}
	else
		return (-1);
	return (0);
}

int				get_figure(char *line, int n, t_figure **place)
{
	t_figure	*figure;

	figure = (t_figure*)malloc(sizeof(t_figure));
	figure->order = 65 + n;
	figure->fig.first.x = 0;
	figure->fig.first.y = 0;
	if (write_coord(&(figure->fig.second.x),
				&(figure->fig.second.y), line, 1) != -1)
		if (write_coord(&(figure->fig.third.x),
					&(figure->fig.third.y), line, 0) != -1)
			if (write_coord(&(figure->fig.fourth.x),
						&(figure->fig.fourth.y), line, 0) != -1)
			{
				*place = figure;
				return (0);
			}
	free(figure);
	return (-1);
}
