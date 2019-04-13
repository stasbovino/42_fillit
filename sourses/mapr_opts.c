/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapr_opts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:31:13 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/03/28 20:10:11 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	restoration(t_square *dst, t_square *src)
{
	int		x;
	int		y;
	int		n;

	n = src->size;
	y = -1;
	while (++y < n)
	{
		x = -1;
		while (++x < n)
			if ((src->map)[y][x] == '!')
				if (dst->map[y][x] == '.')
					(dst->map)[y][x] = '!';
	}
}

int			mapr_opt_init(t_square ***tmp, int *count, int i)
{
	int			k;

	*count = i;
	if (!(*tmp = (t_square**)malloc(sizeof(t_square*) * i)))
		return (-1);
	k = -1;
	while (++k < i)
		(*tmp)[k] = NULL;
	return (0);
}

int			mapr_opt_clean(t_square **tmp, char *eq, int count)
{
	int			k;

	k = -1;
	while (++k < count)
		clean_map(tmp[k]);
	free(tmp);
	if (eq)
		free(eq);
	return (0);
}

int			mapr_opt_rest(t_square **tmp, t_square *dst, char **check)
{
	int		last;
	size_t	len;

//	printf("check is %s\n", check);
	len = ft_strlen(*check);
	if (len == 0 || len == 1)
	{
		free(*check);
		return (0);
	}
	if ((*check)[len - 1] == ' ' || !((*check)[len - 2]) || !(ft_isupper((*check)[len - 2])))
	{
		free(*check);
		return (0);
	}
	last = (*check)[len - 2] - 65;
//	printf("LAST IS:\n");
//	print_map(tmp[last]);
//	printf("tmp[%c]->size %d != dst->size %d\n", last + 65, tmp[last]->size, dst->size);
	if (!tmp[last] || tmp[last]->size != dst->size)
	{
		free(*check);
		return (0);
	}
	restoration(dst, tmp[last]);
	free(*check);
/*	ft_putchar('\n');
	ft_putstr("restored from ");
	ft_putchar(last + 65);
	ft_putchar('\n');
	ft_putchar('\n');*/
//	printf("	restored from %c\n", last + 65);
	return (0);
}


int			mapr_opt_save(t_square **tmp, t_square *dst, int i)
{
	clean_map(tmp[i]);
	if (!(tmp[i] = copy_map(dst, 0)))
		return (-1);
	return (0);
}
