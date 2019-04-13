/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapr_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 19:41:51 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/04/13 20:23:05 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	create_order(char **order, t_square *dst)
{
	int		n;
	char	**tab;
	int		j;
	int		i;
	int		k;

	k = -1;
	n = dst->size;
	tab = dst->map;
	i = -1;
	if (!(*order = ft_strnew(26)))
		return (-1);
	while (++i < n)
	{
		j = -1;
		while (tab[i][++j])
			if (ft_islower(tab[i][j]) && !ft_strchr(*order, tab[i][j] - 32))
				(*order)[++k] = tab[i][j] - 32;
			else if (ft_isupper(tab[i][j]) && !ft_strchr(*order, tab[i][j]))
				(*order)[++k] = tab[i][j];
	}
	return (0);
}

static void	swap_figures(char *eq, char **order, t_square *dst)
{
	int		j;
	char	**tab;
	int		n;

	n = dst->size;
	tab = dst->map;
	j = -1;
	while (++j < n)
		ft_strchr_swap(&tab[j], *(eq + 1), *eq);
	ft_strchr_swap(order, *(eq + 1), *eq);
}

static int	mapr_opt_solut(t_square *dst, char *eq, char *order, int i)
{
	int			j;

	if (eq)
	{
		if (create_order(&order, dst) == -1)
			return (-1);
		while (1)
		{
			j = -1;
			while (eq[++i])
				if (eq[i] == ' ')
					j = -1;
				else
					while (++j >= 0)
						if (!order[j] || order[j] == eq[i])
							break ;
			if (!eq[i])
				break ;
			else
				swap_figures(eq + i - 1, &order, dst);
		}
	}
	free(order);
	print_map(dst);
	return (1);
}

int			map_restore(t_square *dst, char *opt, int i, char *check)
{
	static t_square **tmp = NULL;
	static int		count;
	static char		*eq = NULL;

	if (!tmp)
	{
		if (!(eq = ft_strdup(opt)))
			return (-1);
		return (mapr_opt_init(&tmp, &count, i));
	}
	if (ft_strcmp(opt, "finish") == 0)
		return (mapr_opt_solut(dst, eq, NULL, -1));
	if (ft_strcmp(opt, "clean") == 0)
		return (mapr_opt_clean(tmp, eq, count));
	if (eq && ft_strchr(eq, (char)(i + 65) &&
				ft_strcpy_whilech(&check, eq, (char)(i + 65))))
	{
		if (ft_strcmp(opt, "rest") == 0)
			return (mapr_opt_rest(tmp, dst, &check));
		else if (ft_strcmp(opt, "save") == 0)
			return (mapr_opt_save(tmp, dst, i, &check));
	}
	free(check);
	return (0);
}
