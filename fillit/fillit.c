//#include "libft.h"
//#include "fillit.h"
#include <fcntl.h>
#include <stdio.h>

int		get_figures(int fd)
{
	char	line_sep[5][5];
	char	line[21];
	int		r;

	while ((r = read(fd, line, len)) > 0)
	{

	}
}

int		main(int argc, char **argv)
{
	int	fd;

	if (argc == 1)
	{
		printf("**usage**");
	}
	if (argc  == 2)
	{
		fd = open(argv[1], O_RDONLY);
		get_figures(fd);
	}
	return (1);
}
