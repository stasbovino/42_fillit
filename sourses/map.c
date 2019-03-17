#include "fillit.h"
#include <stdio.h>

void		place_figure(int size, char ***map, t_figure *figure, t_coord pos)
{
	int		i;
	char	s;

	printf("placing\n");
	s = figure->order;
	i = 0;
	(*map)[pos.y][pos.x] = s;
	(*map)[pos.y + figure->fig.second.y][pos.x + figure->fig.second.x] = s;
	(*map)[pos.y + figure->fig.third.y][pos.x + figure->fig.third.x] = s;
	(*map)[pos.y + figure->fig.fourth.y][pos.x + figure->fig.fourth.x] = s;
}

t_coord		*find_pos(int size, char **map)
{
	t_coord	a;
	int		x;
	int		y;
	int		worth;
	int		k;
	int		i;

	k = 2 * size - 1;
	i = 0;
	x = 0;
	y = 0;
	worth = size * 2;
	while (i < (k / 2 + 1))
	{
		x = i;
		y = 0;
		while (x >= 0)
			while (y <= i)
			{
				if (x + y < worth)
				{
					worth = x + y;
					a.x = x;
					a.y = y;
				}
				x--;
				y++;
			}
		i++;
	}
	i = 0;
	while (i < (k / 2))
	{
		x = size;
		y = i + 1;
		while (x >= 0)
			while (y <= size)
			{
				if (x + y < worth)
				{
					worth = x + y;
					a.x = x;
					a.y = y;
				}
				x--;
				y++;
			}
		i++;
	}
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

	if (!map || !*map)
		return ;
	i = 0;
	while (i < size)
	{
		ft_putstr(map[i]);
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

int			test(t_figure **a)
{
	char	**map;
	char	**map2;
	int		size;
	int		sqrt;
	t_coord	pos;

	size = 26 * 4;
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
	pos.x = 0;
	pos.y = 0;
	place_figure(sqrt, &map, a[0], pos);
	print_map(sqrt, map);
	return (0);
}
