/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:06:47 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/03/13 21:14:54 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		check_line(char *tmp, int opt)
{
	int	i;

//	printf("tmp is %s\n", tmp);
	i = 0;
	if (!tmp || !*tmp)
		return (-1);
	if (opt == 1)
	{
//		printf("stroka: slashen\n");
		if (tmp[i] == '\n')
			return (1);
		else
			return (-1);
	}
	while (tmp[i])
	{
//		printf("stroka: tmp[%d] is %c\n", i, tmp[i]);
		if ((tmp[i] != '#') && (tmp[i] != '.') && (i < 4))
		{
//			printf("kek\n");
			return (-1);
		}
		else if (i == 4)
		{
//			printf("stroka: tmp[%d] is slashn\n", i);
			if (tmp[i] != '\n')
				return (-1);
		}
		if (i == 5)
		{
//			printf("kek1\n");
			return (-1);
		}
		i++;
	}
	if (i != 5)
	{
//		printf("kek2\n");
		return (-1);
	}
	return (1);
}

int		find_sharps(char **line, int opt)
{
	static int	k;
	static int	i;

	if (opt == 1)
	{
		k = 0;
		i = 0;
	}
	while ((*line)[i] && ((*line)[i] != '#'))
		i++;
	printf("sharps: i is %d\n", i);
	if ((*line)[i] == '#')
	{
		k++;
		(*line)[i] = 'F';
		printf("line is\n%s\n", *line);
		find_sharps(line, 0);
		find_sharps(line, 0);
		find_sharps(line, 0);
	}
	printf("k is %d\n", k);
	return (1);
}

/*int		find_sharps(char **line, int i)
{
	static int	k;
	int			i;

	i = 0;
	while ((*line)[i] && ((*line)[i] != '#'))
		i++;
	printf("sharps: i is %d\n", i);
	if ((*line)[i] == '#')
	{
		k++;
		(*line)[i] = 'F';
		printf("line is\n%s\n", *line);
		if ((*line)[i + 1] == '#')
			find_sharps(line, 0);
		if ((*line)[i + 5] == '#')
			find_sharps(line, 0);
	}
	return (k);
}*/

int		valid_line(char *line)
{
	char	*tmp;

	tmp = (char*)malloc(sizeof(char) * 26);
	tmp = ft_strcpy(tmp, line);
	printf("tmp is %s\n", tmp);
	if (ft_countchars(tmp, '#') != 4)
	{
		printf("ne chetire\n");
		return (-1);
	}
	if (find_sharps(&tmp, 1) == -1)
	{
		printf("ne nashel\n");
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
	printf("mallocnul\n");
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

t_figure	*read_figure(int fd, int opt)
{
	char		*tmp;
	char		*line;
	int			i;
	static int	n;
	t_figure	*figure;

	if (opt == 1)
		n = 0;
	i = 0;
	if (!(line = ft_strnew(0)))
		return (NULL);
	while (i < 5)
	{
		if (get_next_line(fd, &tmp) == -1)
			return (NULL);
		if (!(tmp = ft_strrejoin(tmp, "\n")))
			return (NULL);
		if (((i == 4) ? check_line(tmp, 1) : check_line(tmp, 0)) == -1)
		{
			printf("ne vishlo\n");
			return (NULL);
		}
		printf("checknul\n");
		if (!(line = ft_strrejoin(line, tmp)))
			return (NULL);
		printf("rejoinul\n");
		free(tmp);
		i++;
	}
	if (valid_line(line) == -1)
	{
		printf("invalid line\n");
		return (NULL);
	}
	printf("line is valid\n");
	if (get_figure(line, n, &figure) == -1)
		return (NULL);
	printf("poluchil figuru\n");
	n++;
	printf("figure is\n");
	printf("%d.%d\n%d.%d\n%d.%d\n%d.%d\n", figure->fig.first.x, figure->fig.first.y,
			figure->fig.second.x, figure->fig.second.y, figure->fig.third.x, figure->fig.third.y,
			figure->fig.fourth.x, figure->fig.fourth.y);
	return (figure);
}
