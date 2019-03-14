#include "libft.h"
#include "fillit.h"
#include <stdio.h>

int		check_line(char *tmp, int opt)
{
	int	i;

	i = 0;
	if (!tmp || !*tmp)
		return (-1);
	if (opt == 1)
	{
		if (tmp[i] == '\n')
			return (1);
		else
			return (-1);
	}
	while (tmp[i])
	{
		if ((tmp[i] != '#') && (tmp[i] != '.') && (i < 4))
			return (-1);
		else if (i == 4)
		{
			if (tmp[i] != '\n')
				return (-1);
		}
		if (i == 5)
			return (-1);
		i++;
	}
	if (i != 5)
		return (-1);
	return (1);
}

int		find_sharps(char **line, int i, int opt)
{
	static int	k;

	if (opt == 1)
		k = 0;
	while ((*line)[i] && ((*line)[i] != '#'))
		i++;
	if ((*line)[i] == '#')
	{
		k++;
		(*line)[i] = 'F';
		if (i < 20 && (*line)[i + 1] == '#')
			find_sharps(line, i + 1, 0);
		if (i > 0 && (*line)[i - 1] == '#')
			find_sharps(line, i - 1, 0);
		if (i < 16 && (*line)[i + 5] == '#')
			find_sharps(line, i + 5, 0);
		if (i > 4 && (*line)[i - 5] == '#')
			find_sharps(line, i - 5, 0);
	}
	return (k);
}

int		valid_line(char *line)
{
	char	*tmp;
	int		i;

	tmp = (char*)malloc(sizeof(char) * 26);
	tmp = ft_strcpy(tmp, line);
	if (ft_countchars(tmp, '#') != 4)
	{
		printf("ne chetire\n");
		return (-1);
	}
	while (tmp[i] && tmp[i] != '#')
		i++;
	if (find_sharps(&tmp, 0, 1) != 4)
	{
		printf("ne smejni\n");
		return (-1);
	}
	free(tmp);
	return (1);
}

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

int		get_figure(char *line, int n, t_figure **place)
{
	t_figure *figure;

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
	return (-1);
}

t_figure	*read_figure(int fd)
{
	char		*tmp;
	char		*line;
	int			i;
	static int	n = 0;
	t_figure	*figure;

	i = 0;
	if (!(line = ft_strnew(0)))
		return (NULL);
	while (i < 5)
	{
		if (get_next_line(fd, &tmp) == -1)
			return (NULL);
		if (!(tmp = ft_strrejoin(tmp, "\n"))) //reshi vopros
			return (NULL);
		if (((i == 4) ? check_line(tmp, 1) : check_line(tmp, 0)) == -1)
			return (NULL);
		if (!(line = ft_strrejoin(line, tmp)))
			return (NULL);
		free(tmp);
		i++;
	}
	if (valid_line(line) == -1)
		return (NULL);
	if (get_figure(line, n, &figure) == -1)
		return (NULL);
	n++;
	return (figure);
}
