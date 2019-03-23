#include <stdio.h>
/*
int	kek(int a[10])
{
	int i;

	i = 0;
	while (a[i] != 5)
	{
		if (a[i] == 3)
			a[i] = 10;
		printf("kek\n");
		i++;
	}
	return (0);
}

char *create(void)
{
	char a[6] = "lolkek";

	return (a);
}

int main(void)
{
	int a[6] = {1, 2, 3, 4, 1, 5};
	int i = -1;
	char *b;

	kek(a);
	while (a[++i] != 5)
		printf("%i = d\n", a[i]);
	b = create();
	printf("%s\n", b);
	return (0);
}*/

#include "libft.h"

char *create(char *order, int count, int n)
{
	int c = 65;
	int i = -1;
	int n = 0;
	char *a;
	int nb = 0;

	a = order;
	while (a[++i])
		if (ft_isupper(a[i]))
				n++;
	c += n;
	i = 0;
	while (a[i])
	{

	}
}

int	main(void)
{
	char a[4];

	ft_memset(a, 46, 3);
	a[3] = '\0';
	create(a);
	return (0);
}
