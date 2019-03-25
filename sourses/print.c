/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 17:11:03 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/03/25 21:32:49 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_usage(void)
{
	ft_putstr("usage: ./fillit source_file\n");
	ft_putstr("	Source file must contain between 1 and 26 Tetriminos.\n");
	ft_putstr("	Example of Tetriminos:\n\n");
	ft_putstr("		..#.	.##.	.##.	.#..	....	....	....\n");
	ft_putstr("		..#.	..#.	.#..	.##.	.##.	..##	##..\n");
	ft_putstr("		..#.	..#.	.#..	.#..	.##.	.##.	.##.\n");
	ft_putstr("		..#.	....	....	....	....	....	....\n\n");
	ft_putstr("	Fillit does not rotate figure to place it in better way.\n");
	ft_putstr("	All rotations of figure counts like a new figure.\n");
}

void	print_error(int fd, t_figure **a, int count)
{
	ft_putstr("error\n");
	if (fd != -1)
		close(fd);
	else if (fd >= 0)
		clean_them_all(a, count);
	exit(1);
}
