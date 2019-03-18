#include "fillit.h"
#include <stdio.h>

void		place_figure(t_square *dst, t_figure *figure, t_coord *pos)
{
	int		i;
	char	s;
	char	***map;

	map = &(dst->map);
	printf("placing\n");
	s = figure->order;
	i = 0;
	(*map)[pos->y][pos->x] = s;
	(*map)[pos->y + figure->fig.second.y][pos->x + figure->fig.second.x] = s;
	(*map)[pos->y + figure->fig.third.y][pos->x + figure->fig.third.x] = s;
	(*map)[pos->y + figure->fig.fourth.y][pos->x + figure->fig.fourth.x] = s;
}

int			vlezaet(t_square *src, t_figure *figure, t_coord *pos)
{
	char	**map;
	int		x;
	int		y;

	printf("vlezet li?\n");
	printf("~~~\nfigure is\n%d.%d\n%d.%d\n%d.%d\n%d.%d\n~~~\n", figure->fig.first.x, figure->fig.first.y, figure->fig.second.x, figure->fig.second.y, figure->fig.third.x, figure->fig.third.y, figure->fig.fourth.x, figure->fig.fourth.y);	
	x = pos->x;
	y = pos->y;
	map = src->map;
	if (map[y + figure->fig.second.y][x + figure->fig.second.x])
		if (map[y + figure->fig.second.y][x + figure->fig.second.x] > 'Z' ||
					map[y + figure->fig.second.y][x + figure->fig.second.x]
					< 'A')
			if (map[y + figure->fig.third.y][x + figure->fig.third.x])
				if (map[y + figure->fig.third.y][x + figure->fig.third.x] > 'Z'
						|| map[y + figure->fig.third.y][x + figure->fig.third.x]
						< 'A')
					if (map[y + figure->fig.fourth.y][x + figure->fig.fourth.x])
						if (map[y + figure->fig.fourth.y]
								[x + figure->fig.fourth.x] > 'Z' ||
								map[y + figure->fig.fourth.y]
								[x + figure->fig.fourth.x] < 'A')
							return (1);
	printf("ne vlezla\n");
	return (-1);
}

t_coord		*find_pos(t_square *src, t_figure *figure)
{
	t_coord	*a;
	int		x;
	int		y;
	int		worth;
	int		k;
	int		i;
	char	**map;
	int		size;
	t_coord	test;

	size = src->size;
	map = src->map;
	a = (t_coord*)malloc(sizeof(t_coord));
	k = 2 * size - 2;
	printf("size is %d k is %d\n", size, k + 1);
	i = 0;
	x = 0;
	y = 0;
	worth = (size - 1) * 2;
	printf("worth is %d\n", worth);
	while (i < (k / 2 + 1))
	{
		x = i;
		y = 0;
		printf("i is %d\n", i);
		while (x >= 0 && y <= i)
		{
			printf("x is %d, y is %d, map[y][x] is %c\n", x, y, map[y][x]);
			if (map[y][x] > 'Z' || map[y][x] < 'A')
			{
				if (x + y <= worth)
				{
					test.x = x;
					test.y = y;
					if (vlezaet(src, figure, &test) == 1)
					{
						printf("writing: %d.%d\n", x, y);
						worth = x + y;
						a->x = x;
						a->y = y;
						return (a);
					}
				}
			}
			x--;
			y++;
		}
		i++;
	}
	i = 0;
	printf("the best is %d.%d\n", a->x, a->y);
	while (i < (k / 2))
	{
		x = size - 1;
		y = i + 1;
		printf("i is %d\n", i);
		while (x >= (size - 1 - y) && y <= size - 1)
		{
			printf("x is %d, y is %d, map[y][x] is %c\n", x, y, map[y][x]);
			if (map[y][x] > 90 || map[y][x] < 65)
			{
				if (x + y < worth)
				{
					test.x = x;
					test.y = y;
					if (vlezaet(src, figure, &test) == 1)
					{
						printf("writing: %d.%d\n", x, y);
						worth = x + y;
						a->x = x;
						a->y = y;
						return (a);
					}
				}
			}
			x--;
			y++;
		}
		i++;
	}
	return (NULL);
}

t_square		*create_map(int count)
{
	char		**a;
	int			size;
	int			i;
	int			j;
	t_square	*map;

	map = (t_square*)malloc(sizeof(t_square));
	i = 0;
	size = (int)ft_sqrt(count, 1);
	printf("size is %d x %d\n", size, size);
	if (!(a = (char**)malloc(sizeof(char*) * size)))
		return (NULL);
	while (i < size)
	{
		if (!(a[i] = (char*)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		j = 0;
		while (j < size)
		{
			a[i][j] = i + j + 97;
			j++;
		}
		a[i][size] = '\0';
		i++;
	}
	map->map = a;
	map->size = size;
	return (map);
}

void		print_map(t_square *map)
{
	int		i;
	int		j;
	int		n;
	char	**tab;

	if (!map)
		return ;
	n = map->size;
	tab = map->map;
	i = 0;
	while (i < n)
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] > 'Z' || tab[i][j] < 'A')
				ft_putchar('.');
			else
				ft_putchar(tab[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	return ;
}

int			clean_map(t_square *map)
{
	int		i;
	int		n;

	n = map->size;
	i = 0;
	while (i < n)
	{
		printf("%d", i);
		free((map->map)[i]);
		i++;
	}
	free(map->map);
	map->map = NULL;
	free(map);
	map = NULL;
	return (-1);
}

t_square		*copy_map(t_square *src)
{
	int		i;
	char	**map;
	t_square *a;
	int			n;

	n = src->size;
	if (!(a = (t_square*)malloc(sizeof(t_square))))
		return (NULL);
	if (!(map = (char**)malloc(sizeof(char*) * n)))
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (!(map[i] = (char*)malloc(sizeof(char) * (n + 1))))
			return (NULL);
		map[i] = ft_strcpy(map[i], (src->map)[i]);
		i++;
	}
	a->map = map;
	a->size = n;
	return (a);
}

int				test(t_figure **a, int count)
{
	t_square	*map;
	t_square	*map2;
	int			size;
	int			sqrt;
	t_coord		*pos;
	int			i;

	i = 0;
	size = count * 4;
	if (!(map = create_map(size)))
	{
		printf("ne sozdal\n");
		return (0);
	}
	printf("map is:\n");
	print_map(map);
	if (!(map2 = copy_map(map)))
	{
		printf("ne skopiroval\n");
		return (0);
	}
	printf("map2 is:\n");
	print_map(map2);
	pos->x = 0;
	pos->y = 0;
	while (i < count)
	{
		if (!(pos = find_pos(map, a[i])))
		{
			printf("blya\n");
			break;
		}
		else
		{
			printf("figure is %d of %d\npos is %d.%d\n", i, count, pos->x, pos->y);
			place_figure(map, a[i], pos);
			print_map(map);
			i++;
		}
	}
	return (0);
}
