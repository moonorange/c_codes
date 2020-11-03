int     ft_recursive_power(int nb, int power)
{
	int ans;

	if (power < 0)
		return (0);
	if (power == 0)
        return (1);
    return (ft_recursive_power(nb, power - 1) * nb);
}

#include <stdio.h>
int     main(int argc, char **argv)
{
    printf("%d\n",ft_recursive_power(5, 2));
    printf("%d\n",ft_recursive_power(2, 3));
    printf("%d\n",ft_recursive_power(-1, 3));
    printf("%d\n",ft_recursive_power(-1, 0));
    printf("%d\n",ft_recursive_power(0, 0));
    printf("%d\n",ft_recursive_power(5, 7));
}
