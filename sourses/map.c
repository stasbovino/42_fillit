#include "fillit.h"
#include <stdio.h>

int			create_map(char ***map, int count)
{
	char	**a;
	int		size;
	int		i;

	i = 0;
	size = (int)ft_sqrt(count, 1);
	printf("size is %d\n", size);
	if (!(a = (char**)malloc(sizeof(char*) * size)))
		return (-1);
	while (i < size)
	{
		if (!(a[i] = (char*)malloc(sizeof(char) * (size + 1))))
			return (-1);
		ft_memset(a[i], 46, size);
		a[i][size] = '\0';
		printf("%s\n", a[i]);
		i++;
	}
	map = &a;
	return (1);
}

void		print_map(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		ft_putstr(map[i]);
		i++;
	}
	return ;
}

int			clean_map(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
	return (-1);
}

char		**copy_map(char **src)
{
	int		i;
	char	**map;

	i = 0;
	while (src[i])
		i++;
	if (!(map = (char**)malloc(sizeof(char*) * i)))
		return (NULL);
	i = 0;
	while (map[i])
	{
		if (!(map[i] = (char*)malloc(sizeof(char) * ft_strlen(src[i]))))
			return (NULL);
		map[i] = ft_strcpy(map[i], src[i]);
		i++;
	}
	return (map);
}

int		main(void)
{
	char **map;
	char **map2;

	if (create_map(&map, 25) != 1)
	{
		printf("ne sozdal\n");
		return (0);
	}
	printf("%s\n", map[0]);
	printf("map is:\n");
	print_map(map);
	if (!(map2 = copy_map(map)))
	{
		printf("ne skopiroval\n");
		return (0);
	}
	printf("map2 is:\n");
	print_map(map2);
	if (clean_map(map) == -1)
		printf("pochistil1\n");
	print_map(map);
	if (clean_map(map2) == -1)
		printf("pochistil2\n");
	return (0);
}
