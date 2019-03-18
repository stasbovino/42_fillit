#include "fillit.h"
#include <stdio.h>

void		place_figure(int size, char ***map, t_figure *figure, t_coord *pos)
{
	int		i;
	char	s;

	printf("placing\n");
	s = figure->order;
	i = 0;
	(*map)[pos->y][pos->x] = s;
	(*map)[pos->y + figure->fig.second.y][pos->x + figure->fig.second.x] = s;
	(*map)[pos->y + figure->fig.third.y][pos->x + figure->fig.third.x] = s;
	(*map)[pos->y + figure->fig.fourth.y][pos->x + figure->fig.fourth.x] = s;
}

int			vlezaet(int size, char **map, t_figure *figure, int x, int y)
{
//	printf("~~~\nfigure is\n%d.%d\n%d.%d\n%d.%d\n%d.%d\n~~~\n", figure->fig.first.x, figure->fig.first.y, figure->fig.second.x, figure->fig.second.y, figure->fig.third.x, figure->fig.third.y, figure->fig.fourth.x, figure->fig.fourth.y);
	if (map[y + figure->fig.second.y][x + figure->fig.second.x] > 90 ||
			map[y + figure->fig.second.y][x + figure->fig.second.x] < 65)
		if (map[y + figure->fig.third.y][x + figure->fig.third.x] > 90 ||
			map[y + figure->fig.third.y][x + figure->fig.third.x] < 65)
			if (map[y + figure->fig.fourth.y][x + figure->fig.fourth.x] > 90 ||
			map[y + figure->fig.fourth.y][x + figure->fig.fourth.x] < 65)
			{
				printf("vlezlo\n");
				return (1);
			}
	return (-1);
}


t_coord		*find_pos(int size, char **map, t_figure *figure)
{
	t_coord	*a;
	int		x;
	int		y;
	int		worth;
	int		k;
	int		i;

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
					if (vlezaet(size, map, figure, x, y) == 1)
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
					if (vlezaet(size, map, figure, x, y) == 1)
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
	return (a);
}

char		**create_map(int *size_back, int count)
{
	char	**a;
	int		size;
	int		i;
	int		j;

	j = 0;
	i = 0;
	size = (int)ft_sqrt(count, 1);
	*size_back = size;
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
	return (a);
}

void		print_map(int size, char **map)
{
	int		i;
	int		j;

	if (!map || !*map)
		return ;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] > 'Z' || map[i][j] < 'A')
				ft_putchar('.');
			else
				ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	return ;
}

int			clean_map(int size, char **map)
{
	int		i;

	i = 0;
	while (i < size)
	{
		printf("%d", i);
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
	return (-1);
}

char		**copy_map(int size, char **src)
{
	int		i;
	char	**map;

	if (!(map = (char**)malloc(sizeof(char*) * size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!(map[i] = (char*)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		map[i] = ft_strcpy(map[i], src[i]);
		i++;
	}
	return (map);
}

int			test(t_figure **a, int count)
{
	char	**map;
	char	**map2;
	int		size;
	int		sqrt;
	t_coord	*pos;
	int i;

	i = 0;
	size = count * 4;
	if (!(map = create_map(&sqrt, size)))
	{
		printf("ne sozdal\n");
		return (0);
	}
	printf("map is:\n");
	print_map(sqrt, map);
	if (!(map2 = copy_map(sqrt, map)))
	{
		printf("ne skopiroval\n");
		return (0);
	}
	printf("map2 is:\n");
	print_map(sqrt, map2);
	pos->x = 0;
	pos->y = 0;
	while (i < count)
	{
		pos = find_pos(4, map, a[i]); 
		printf("pos is %d.%d\n", pos->x, pos->y);
		place_figure(sqrt, &map, a[i], pos);
		print_map(sqrt, map);
		i++;
	}
	return (0);
}
