//#include "libft.h"
//#include "fillit.h"
#include <fcntl.h>
#include <stdio.h>

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
