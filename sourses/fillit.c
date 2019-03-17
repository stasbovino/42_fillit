include "fillit.h"
#include <stdio.h>

int			create_map(char ***map, int count)
{
	char	**a;
	int		size;
	int		i;

	i = 0;
	size = (int)ft_sqrt(count, 1);
	if (!(a = (char**)malloc(sizeof(char*) * size)))
		return (-1);
	while (i < size)
	{
		if (!(a[i] = (char*)malloc(sizeof(char) * (size + 1))))
			return (-1);
		a[size] = '\0';
		i++;
	}
	map = &a;
	return (1);
}

int			place_figure(char ***map, t_figure *figure, t_coord pos)
{
	int		i;

	i = 0;
}

int			fill_it(t_figure **figures, int count)
{
	char	**map;
	char	**thebest

	if (create_map(&map, count * 4) != 1)
		return (-1);
}
