#include "fillit.h"
#include "libft.h"
#include <stdio.h>

int		write_coord(int *x, int *y, char *line, int opt)
{
	static int i;
	static int start;

	if (opt == 1)
	{
		i = 0;
		while (line[i] && (line[i] != '#'))
			i++;
		start = i;
		i++;
	}
	while (line[i] && (line[i] != '#'))
		i++;
	if (line[i] == '#')
	{
		*x = (i % 5) - (start % 5);
		*y = (i / 5) - (start / 5);
		i++;
	}
	else
		return (-1);
	return (0);
}

int		get_figure(char *line, int n)
{
	t_figure *figure;

	figure = (t_figure*)malloc(sizeof(t_figure));
	figure->order = 65 + n;
	figure->fig.first.x = 0;
	figure->fig.first.y = 0;
	if (write_coord(&(*figure)->fig.second.x,
				&(*figure)->fig.second.y, line, 1) != -1)
		if (write_coord(&(*figure)->fig.third.x,
					&(*figure)->fig.third.y, line, 0) != -1)
			if (write_coord(&(*figure)->fig.fourth.x,
						&(*figure)->fig.fourth.y, line, 0) != -1)
				return (0);
	return (-1);
}

int		main(int argc, char **argv)
{
	char *tmp = "##..\n.##.\n....\n....\n\n";

	get_figure(tmp, 0);
	return (0);
}
