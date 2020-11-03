
int	    ft_iterative_factorial(int nb)
{
	int	ans;
	int	idx;

	if (nb < 0)
		return (0);
	idx = 1;
	ans = 1;
	while (idx <= nb)
		ans = ans * idx++;
	return (ans);
}

#include <stdio.h>
int     main(void)
{
    int n = -1;
    while (n <= 10)
    {
        printf("%d! = %d\n", n, ft_iterative_factorial(n));
        n++;
    }
}

