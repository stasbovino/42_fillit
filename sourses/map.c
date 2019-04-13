/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 21:07:36 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/04/13 18:34:52 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_square		*create_map(int size)
{
	char		**a;
	int			i;
	int			j;
	t_square	*map;

	if (!(map = (t_square*)malloc(sizeof(t_square))))
		return (NULL);
	i = 0;
	if (!(a = (char**)malloc(sizeof(char*) * size)))
		return (NULL);
	while (i < size)
	{
		if (!(a[i] = (char*)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		j = -1;
		while (++j < size)
			a[i][j] = '.';
		a[i++][size] = '\0';
	}
	map->map = a;
	map->size = size;
	return (map);
}

void			print_map(t_square *map)
{
	int			i;
	int			j;
	int			n;
	char		**tab;

	if (!map)
		return ;
	n = map->size;
	tab = map->map;
	i = -1;
	while (++i < n)
	{
		j = 0;
		while (tab[i][j])
		{
			if (ft_islower(tab[i][j]))
				ft_putchar(tab[i][j] - 32);
			if (tab[i][j] == '!')
				ft_putchar('.');
			if (ft_isupper(tab[i][j]) || tab[i][j] == '.')
				ft_putchar(tab[i][j]);
			j++;
		}
		ft_putchar('\n');
	}
}

int				clean_map(t_square *map)
{
	int			i;
	int			n;

	if (!map)
		return (0);
	n = map->size;
	i = 0;
	while (i < n)
	{
		free((map->map)[i]);
		i++;
	}
	free(map->map);
	map->map = NULL;
	free(map);
	map = NULL;
	return (-1);
}

t_square		*copy_map(t_square *src, int opt)
{
	int			i;
	char		**map;
	t_square	*a;
	int			n;
	int			j;

	n = src->size;
	if (!(a = (t_square*)malloc(sizeof(t_square))))
		return (NULL);
	if (!(map = (char**)malloc(sizeof(char*) * n)))
		return (NULL);
	i = -1;
	while (++i < n)
	{
		j = -1;
		if (!(map[i] = (char*)malloc(sizeof(char) * (n + 1))))
			return (NULL);
		map[i] = ft_strcpy(map[i], (src->map)[i]);
		while (++j < n)
			if (map[i][j] == '!' && opt == 1)
				map[i][j] = '.';
	}
	a->map = map;
	a->size = n;
	return (a);
}
