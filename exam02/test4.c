#include <stdlib.h>
#include <stdbool.h>

int     *ft_range(int min, int max)
{
    int     sign;
    int     idx;
    int     area;
    int     *array;

    sign = 1;
    if (max < min)
        sign *= -1;
    if (sign < 0)
        area = min - max + 1;
    else
        area = max - min + 1;
    array = (int *)malloc(area * sizeof(int));
    if (array == NULL)
        return (0);
    idx = 0;
    while (idx < area)
    {
        array[idx] = min + idx * sign;
        idx++;
    }
    return (array);
}

#include <stdio.h>
int     main(int argc, char **argv)
{
    int *array;
    int n = 0;
    int min = atoi(argv[1]);
    int max = atoi(argv[2]);
    int range;

    array = ft_range(min, max);

    if (min > max)
        range = min - max;
    else
    {
        range = max - min;
    }

    while (n < range)
    {
        printf("%d\n", *array);
        n++;
        array++;
    }
}
