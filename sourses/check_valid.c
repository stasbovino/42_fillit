/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:01:40 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/03/23 15:40:37 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*
 *	checking one line of file for other symbols besides '#' and '.'
 *							  and length of line must be 4
 */

int				check_line(char *tmp)
{
	int			i;

	i = 0;
	if (!tmp || !*tmp)
		return (-1);
	if (ft_strlen(tmp) != 4)
		return (-1);
	while (tmp[i])
	{
		if ((tmp[i] != '#') && (tmp[i] != '.'))
			return (-1);
		i++;
	}
	return (1);
}

/*
 *	recursive func for checking the figure
 *	represented in one line without \n
 *	for valid figure in it
 *
 *	counting the number of nearbly sharps
 *	it must be 4 for valid figure
 *
 *	"..#...#...#...#."
 */

int				find_sharps(char **line, int i, int opt)
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
		if (i < 15 && (*line)[i + 1] == '#')
			find_sharps(line, i + 1, 0);
		if (i > 0 && (*line)[i - 1] == '#')
			find_sharps(line, i - 1, 0);
		if (i < 12 && (*line)[i + 4] == '#')
			find_sharps(line, i + 4, 0);
		if (i > 3 && (*line)[i - 4] == '#')
			find_sharps(line, i - 4, 0);
	}
	return (k);
}

/*
 *	checking the figure represented in one line without \n
 *	
 *	e.g.	"..#...#...#...#."
 *			"......##..##...."
 *	
 *	the number of '#' must be 4 and each other must be nearbly with other '#'
 */

int				valid_line(char *line)
{
	char		*tmp;
	int			i;

	tmp = (char*)malloc(sizeof(char) * 17);
	tmp = ft_strcpy(tmp, line);
	if (ft_countchars(tmp, '#') != 4)
	{
		free(tmp);
		return (-1);
	}
	i = (int)ft_strchrpos(line, '#');
	if (find_sharps(&tmp, 0, 1) != 4)
	{
		free(tmp);
		return (-1);
	}
	free(tmp);
	return (1);
}
