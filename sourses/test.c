#include <stdio.h>

int		main(void)
{
	int i;
	char a[2];
	i = 0;
/*	while (i < 5)
	{
		printf("%d\n", i++);
		printf("%d\n", i);
	}*/
	a[i++] = 65 + i;
	printf("%c %c\n", 65, a[i - 1]);
	return (0);
}
