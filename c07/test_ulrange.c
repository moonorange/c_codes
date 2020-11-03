#include <stdlib.h>
#include <stdio.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int	bound;
	int	index;
	int	*buffer;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	bound = max - min - 1;
	if ((buffer = malloc(bound * sizeof(int))) == NULL)
	{
		*range = 0;
		return (-1);
	}
	*range = buffer;
	index = 0;
	while (index <= bound)
	{
		buffer[index] = min + index;
		index++;
	}
	return (bound + 1);
}

void	debug_dump_array(int numbers[], int size)
{
	int index;

	printf("[ ");
	index = 0;
	while (index < size)
	{
		printf("%d", numbers[index]);
		if (index != size - 1)
		{
			printf(", ");
		}
		index++;
	}
	printf(" ]\n");
}

int		main(void)
{
	int	min;
	int	max;
	int	*range;
	int	bound;

	min = 10;
	max = 1;
	bound = ft_ultimate_range(&range, min, max);
	printf("min = %d, max = %d -> (bound = %d) ", min, max, bound);
	debug_dump_array(range, bound);
}
