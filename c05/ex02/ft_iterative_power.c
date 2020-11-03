int     ft_iterative_power(int nb, int power)
{
	int ans;

	if (power < 0)
		return (0);
	ans = 1;
	while (power-- > 0)
		ans *= nb;
	return (ans);
}

#include <stdio.h>
int     main(int argc, char **argv)
{
    printf("%d\n",ft_iterative_power(5, 2));
    printf("%d\n",ft_iterative_power(2, 3));
    printf("%d\n",ft_iterative_power(-1, 3));
    printf("%d\n",ft_iterative_power(-1, 0));
    printf("%d\n",ft_iterative_power(0, 0));
    printf("%d\n",ft_iterative_power(5, 7));
}
