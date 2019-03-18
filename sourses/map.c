#include "fillit.h"
#include <stdio.h>

void		place_figure(t_square *dst, t_figure *figure, t_coord *pos)
{
	int		i;
	char	s;
	char	***map;

	map = &(dst->map);
	s = figure->order;
	i = 0;
	(*map)[pos->y][pos->x] = s;
	(*map)[pos->y + figure->fig.second.y][pos->x + figure->fig.second.x] = s;
	(*map)[pos->y + figure->fig.third.y][pos->x + figure->fig.third.x] = s;
	(*map)[pos->y + figure->fig.fourth.y][pos->x + figure->fig.fourth.x] = s;
}

int			check_borders(int size, int x, int y)
{
	if (x < size && y < size && x >= 0 && y >= 0)
		return (1);
	else
		return (0);
}

int			vlezaet(t_square *src, t_figure *figure, int x, int y)
{
	char	**map;

	map = src->map;
	if (check_borders(src->size, y + figure->fig.second.y,
				x + figure->fig.second.x))
		if (!(ft_isupper(map[y + figure->fig.second.y][x + figure->fig.second.x])))
			if (check_borders(src->size, y + figure->fig.third.y,
						x + figure->fig.third.x))
				if (!(ft_isupper(map[y + figure->fig.third.y][x + figure->fig.third.x])))
					if (check_borders(src->size, y + figure->fig.fourth.y,
								x + figure->fig.fourth.x))
						if (!(ft_isupper(map[y + figure->fig.fourth.y]
								[x + figure->fig.fourth.x])))
							return (1);
	return (-1);
}

t_coord		*first_diag(t_square *src, t_figure *figure, int k, int worth)
{
	int i;
	int x;
	int y;

	i = -1;
	while (++i < (k / 2 + 1))
	{
		x = i;
		y = 0;
		while (x >= 0 && y <= i)
		{
			if (!(ft_isupper((src->map)[y][x])))
				if (x + y <= worth)
					if (vlezaet(src, figure, x, y) == 1)
					{
						worth = x + y;
						return (ft_create_coords(x, y));
					}
			x--;
			y++;
		}
	}
	return (NULL);
}

t_coord		*second_diag(t_square *src, t_figure *figure, int k, int worth)
{
	int i;
	int x;
	int y;

	i = -1;
	while (++i < (k / 2))
	{
		x = src->size - 1;
		y = i + 1;
		while (x >= (src->size - 1 - y) && y <= src->size - 1)
		{
			if (!(ft_isupper((src->map)[y][x])))
				if (x + y < worth)
					if (vlezaet(src, figure, x, y) == 1)
					{
						worth = x + y;
						return (ft_create_coords(x, y));
					}
			x--;
			y++;
		}
	}
	return (NULL);
}

t_coord		*find_pos(t_square *src, t_figure *figure)
{
	t_coord	*a;
	int k;
	int worth;

	k = 2 * src->size - 2;
	worth = (src->size - 1) * 2;
	if (!(a = first_diag(src, figure, k, worth)))
		if (!(a = second_diag(src, figure, k, worth)))
			return (NULL);
	return (a);
/*	while (++i < (k / 2 + 1))
	{
		x = i;
		y = 0;
		while (x >= 0 && y <= i)
		{
			if (!(ft_isupper((src->map)[y][x])))
				if (x + y <= worth)
				{
					ft_get_coords(&test, x, y);
					if (vlezaet(src, figure, &test) == 1)
					{
						worth = x + y;
						ft_get_coords(a, x, y);
						return (a);
					}
				}
			x--;
			y++;
		}
	}
	i = -1;
	while (++i < (k / 2))
	{
		x = src->size - 1;
		y = i + 1;
		while (x >= (src->size - 1 - y) && y <= src->size - 1)
		{
			if (!(ft_isupper((src->map)[y][x])))
				if (x + y < worth)
				{
					ft_get_coords(&test, x, y);
					if (vlezaet(src, figure, &test) == 1)
					{
						worth = x + y;
						ft_get_coords(a, x, y);
						return (a);
					}
				}
			x--;
			y++;
		}
	}*/
	return (NULL);
}

t_square		*create_map(int count)
{
	char		**a;
	int			size;
	int			i;
	int			j;
	t_square	*map;

	if (!(map = (t_square*)malloc(sizeof(t_square))))
		return (NULL);
	i = 0;
	size = (int)ft_sqrt(count, 1);
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
		ft_putnbr(i);
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
//	ft_putstr(" 0123456789\n");
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
	int			i;
	char		**map;
	t_square	*a;
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
