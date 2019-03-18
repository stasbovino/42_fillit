#include <stdio.h>
#include "libft.h"

#define RESET		"\033[0m"

int main()
{
	int i;
	char *color;
	char *a;
	char *new;
	int b;

	b = 'A';
	printf("b is %d\n", b);
	color = ft_strnew(0);
	color = ft_strrejoin(color, "\033[1;");
	i = 30;
	while (i < 39)
	{
		new = ft_strnew(0);
		a = ft_itoa(i);
		new = ft_strjoin(color, a);
		new = ft_strjoin(new, "m");
		printf("%scolortext%s\n", new, RESET);
		free(new);
		i++;
	}
}
