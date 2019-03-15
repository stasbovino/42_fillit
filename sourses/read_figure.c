/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_figure.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:10:00 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/03/15 14:21:18 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int				end_reading(int fd)
{
	char		*tmp;

	while (get_next_line(fd, &tmp) != 0)
		free(tmp);
	free(tmp);
	return (-1);
}

int				read_one_line(int fd, char **line)
{
	int			i;
	char		*tmp;
	int			r;

	i = -1;
	while (++i < 5)
	{
		r = get_next_line(fd, &tmp);
		if (i != 4)
		{
			if (r != 1)
				break ;
			if (check_line(tmp) == -1)
				break ;
			if (!(*line = ft_strrejoin(*line, tmp)))
				break ;
		}
		free(tmp);
	}
	if (i == 5)
		return (1);
	free(tmp);
	return (end_reading(fd));
}

t_figure		*read_figure(int fd, int n)
{
	char		*line;
	t_figure	*figure;

	if (!(line = ft_strnew(0)))
		return (NULL);
	if (read_one_line(fd, &line) == -1)
	{
		free(line);
		return (NULL);
	}
	if (valid_line(line) == -1)
	{
		free(line);
		return (NULL);
	}
	if (get_figure(line, n, &figure) == -1)
	{
		free(line);
		return (NULL);
	}
	free(line);
	return (figure);
}
