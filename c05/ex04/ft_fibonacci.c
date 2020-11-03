int     ft_fibonacci(int index)
{
    if (index < 0)
        return (-1);
    if (index < 2)
        return (index);
    return (ft_fibonacci(index - 2) + ft_fibonacci(index - 1));
}

#include <stdio.h>

int main(void)
{
	for(int i = -2; i < 10; i++)
		printf("%d, %d\n", i, ft_fibonacci(i));
	return 0;
}
