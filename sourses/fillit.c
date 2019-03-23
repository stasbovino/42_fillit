/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 21:37:38 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/03/22 19:41:17 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*int				fill_it(t_figure **figures, int count)
{
	t_square	*map;
	char		order[count + 1];
	static int	size = count * 4;

	order[count] = '\0';
	if (!(map = create_map(count * 4)))
	{
		printf("ne sozdal\n");
		return (0);
	}

}

char			*create_order(char *order)
{
	if (order[count])
	{
		order[count]
	}
	else
	{

		return (*order);
	}
}
*/
int				test(t_figure **a, int count)
{
	t_square	*map;
	int			size;
	t_coord		*pos;
	int			i;

	i = 0;
	size = count * 4;
	if (!(map = create_map(size)))
	{
		printf("ne sozdal\n");
		return (0);
	}
	printf("map is:\n");
	print_map(map);
	printf("end\n");
	while (i < count)
	{
		printf("posfind\n");
		if (!(pos = find_pos(map, a[i])))
		{
			printf("blya\n");
			break;
		}
		else
		{
			printf("figure is %d of %d\npos is %d.%d\n", i + 1, count, pos->x, pos->y);
			place_figure(map, a[i], pos);
			print_map(map);
			free(pos);
			i++;
		}
	}
	clean_map(map);
	return (0);
}

