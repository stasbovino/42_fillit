/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:01:55 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/03/15 14:01:57 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <fcntl.h>
#include <stdio.h>

int		count_figures(int fd)
{
	int		r;
	char	*line;
	size_t	count;
	size_t	n;

	count = 0;
	while ((r = get_next_line(fd, &line)) > 0)
	{
		free(line);
		count++;
	}
	free(line);
	if (((count + 1) % 5) != 0)
		return (-1);
	n = (count + 1) / 5;
	if ((n == 0) || (n > 26))
		return (-1);
	return (n);
}

int		clean_them_all(t_figure **a, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		printf("freed %d\n", i);
		free(a[i]);
		i++;
	}
	free(a);
	a = NULL;
	return (-1);
}

int		main(int argc, char **argv)
{
	int			fd;
	t_figure	**a;
	int			i;
	int			count;

	if (argc == 1)
	{
		printf("**usage**");
	}
	if (argc == 2)
	{
		i = 0;
		fd = open(argv[1], O_RDONLY);
		if ((count = (int)count_figures(fd)) == -1)
		{
			printf("mnogo ili malo figur ili slashenov\n\n");
			return (0);
		}
		close(fd);
		fd = open(argv[1], O_RDONLY);
		printf("%d figures\n\n", count);
		a = (t_figure**)malloc(sizeof(t_figure*) * count);
		while (i < count)
		{
			a[i] = read_figure(fd, i);
			if (!a[i])
			{
				printf("a[%d] ne schitalos' invalid\n", i);
				clean_them_all(a, count);
				return (0);
			}
			printf("order is %c\n", a[i]->order);
			printf("~~~\nfigure is\n%d.%d\n%d.%d\n%d.%d\n%d.%d\n~~~\n", a[i]->fig.first.x, a[i]->fig.first.y, a[i]->fig.second.x, a[i]->fig.second.y, a[i]->fig.third.x, a[i]->fig.third.y, a[i]->fig.fourth.x, a[i]->fig.fourth.y);
			i++;
		}
		clean_them_all(a, count);
	}
	return (0);
}
