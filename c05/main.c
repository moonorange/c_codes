// ex01
#include <stdio.h>
int     main(void)
{
    int n = -1;
    while (n <= 10)
    {
        printf("%d! = %d\n", n, ft_iterative_factorial(n));
        n++;
    }
    printf("%d! = %d\n", 31, ft_iterative_factorial(31));
}

// ex01
#include <stdio.h>
int     main(void)
{
    int n = -1;
    while (n <= 10)
    {
        printf("%d! = %d\n", n, ft_recursive_factorial(n));
        n++;
    }
    printf("%d! = %d\n", 31, ft_recursive_factorial(31));
}

// ex02
#include <stdio.h>
int     main(void)
{
    printf("%d\n",ft_iterative_power(5, 2));
    printf("%d\n",ft_iterative_power(2, 3));
    printf("%d\n",ft_iterative_power(-1, 3));
    printf("%d\n",ft_iterative_power(2147483647, 0));
    printf("%d\n",ft_iterative_power(0, 0));
    printf("%d\n",ft_iterative_power(-10, 9));
    printf("%d\n",ft_iterative_power(10, 9));
}

// ex03
#include <stdio.h>
int     main(void)
{
    printf("%d\n",ft_recursive_power(5, 2));
    printf("%d\n",ft_recursive_power(2, 3));
    printf("%d\n",ft_recursive_power(-1, 3));
    printf("%d\n",ft_recursive_power(2147483647, 0));
    printf("%d\n",ft_recursive_power(0, 0));
    printf("%d\n",ft_recursive_power(-10, 9));
    printf("%d\n",ft_recursive_power(10, 9));
}

#include <stdio.h>
int     main(void)
{
    int i;
    for (i=0; i <= 100; i++)
printf("%d\n", ft_recursive_power(i, 4));
}



// ex04
#include <stdio.h>

int main(void)
{
    for(int i = -2; i < 40; i++)
        printf("%d, %d\n", i, ft_fibonacci(i));
}

// ex05
#include <stdio.h>

int main(void)
{
    printf("%d\n", ft_sqrt(4));
    printf("%d\n", ft_sqrt(16));
    printf("%d\n", ft_sqrt(-4));
    printf("%d\n", ft_sqrt(0));
    printf("%d\n", ft_sqrt(1));
    printf("%d\n", ft_sqrt(2147483647));
    printf("%d\n", ft_sqrt(-2147483648));
    printf("%d\n", ft_sqrt(1600000000));
}


// ex06
#include <stdio.h>

int main(void)
{
    for (int i = -1; i < 100; i++)
        printf("%d, %d\n", i, ft_is_prime(i));
    printf("%d, %d\n", 2049582589, ft_is_prime(2049582589));
    printf("%d, %d\n", 2147483647, ft_is_prime(2147483647));
    return 0;
}

// ex07
#include <stdio.h>
int main(void)
{
    int idx;

    idx = -2;
    while (idx < 50)
    {
        printf("%d's closest prime num is %d\n", idx, ft_find_next_prime(idx));
        idx++;
    }
    printf("%ld's closest prime num is %d\n", -2147483648, ft_find_next_prime(-2147483648));
}
