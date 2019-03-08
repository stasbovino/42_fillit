//#include "libft.h"
//#include "fillit.h"
#include <fcntl.h>
#include <stdio.h>

int		check_valid(int fd)
{
	char	line[21];
	int		r;
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (k < 26)
	{
		while ((i < 5) && ((r = get_next_line(fd, &line)) > 0))
		{

		}
		//konec
		i = 0;
		k++;
	}
}



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
		if (check_valid(fd) == -1)
			return (-1); //PRINTERROR VALID
		get_figures(fd);
	}
	return (1);
}
