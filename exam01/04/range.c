#include <stdlib.h>

int     *ft_range(int start, int end)
{
    int     sign;
    int     idx;
    int     area;
    int     *array;

    sign = 1;
    if (end < start)
        sign *= -1;
    if (sign < 0)
        area = start - end + 1;
    else
        area = end - start + 1;
    array = (int *)malloc(area * sizeof(int));
    idx = 0;
    while (idx < area)
    {
        array[idx] = start + idx * sign;
        idx++;
    }
    return (array);
}

#include <stdio.h>
int     main(void)
{
    int *array;
    int n = 0;
    array = ft_range(1, -1);

    while (n < sizeof(array))
    {
        printf("%d\n", *array);
        n++;
        array++;
    }
}
