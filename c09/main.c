// ex02
#include <stdio.h>
int		main(int argc, char **argv)
{
	int		idx;
	char	**array;

	argc = argc + 0;
	array = ft_split(argv[1], argv[2]);
	idx = 0;
	while (array[idx])
	{
		printf("array[%d]: %s\n", idx, array[idx]);
		idx++;
	}
}

// ./a.out "IiYfidiJuYYolWJgeyMWm7we5b9GcMFuOT 67vi7" ""
