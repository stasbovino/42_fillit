#include "libft.h"
#include "fillit.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int	fd;
	t_figure **a;
	int	i;

	if (argc == 1)
	{
		printf("**usage**");
	}
	if (argc  == 2)
	{
		i = 0;
		fd = open(argv[1], O_RDONLY);
		a = (t_figure**)malloc(sizeof(t_figure*) * NUM_OF_FIGURES); //SDELAI FUNC NA PODSCHET HUEVIN
		while (i < NUM_OF_FIGURES)
		{
			ft_putstr("DAROVA\n");
			a[i] = read_figure(fd, 1);
			if (!a[i])
				printf("hui\n");
			ft_putstr("prochital\n");
			printf("order is %c\n", a[i]->order);
		/*	printf("~~~\norder of is %c\nfigure is\n%d.%d\n%d.%d\n%d.%d\n%d.%d\n~~~\n", a[i]->fig.first.x, a[i]->fig.first.y,
					a[i]->fig.second.x, a[i]->fig.second.y, a[i]->fig.third.x, a[i]->fig.third.y,
					a[i]->fig.fourth.x, a[i]->fig.fourth.y); */
			i++;
		}
	}
	return (0);
}
