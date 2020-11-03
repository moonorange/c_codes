// ex00
#include <stdio.h>
#include <string.h>

int     main(int argc, char **argv)
{
    argc = 0;
    argv = 0;
    char    *test = "Hello World";
    printf("my: %s\n", ft_strdup(test));
    printf("c's %s\n", strdup(test));
    printf("old_m %p\n", test);
    printf("new_m: %p\n", ft_strdup(test));
    printf("my: %s\n", ft_strdup("gajkn24 kwen 2 3%$&"));
    printf("c's %s\n", strdup("gajkn24 kwen 2 3%$&"));
}


// ex01

#include <stdio.h>

int     main(int argc, char **argv)
{
    argc = 0;
    int     idx = 0;
    int     range;
    int     *test;
    int     min = atoi(argv[1]);
    int     max = atoi(argv[2]);

    range = max - min;
    test = ft_range(min, max);
    if (test)
    {
        while(idx < range)
            printf("%d\n", test[idx++]);
    }
    else
        return (0);
}

// ex02
int     main(void)
{
    int min;
    int max;
    int *range;
    int area;

    min = 5;
    max = 10;
    area = ft_ultimate_range(&range, min, max);
    printf("min = %d, max = %d area = %d: ", min, max, area);
    printf("array");
    int idx = 0;
    while (idx < area)
    {
        printf("%d,", range[idx]);
        idx++;
    }
}

// ex03
#include <stdio.h>
int     main(void)
{
    int     size;
    char    **strs;
    char    *sep;
    char    *result;

    strs = (char**)malloc(6 * sizeof(strs));
    strs[0] = "Hello";
    strs[1] = " ";
    strs[2] = "World";
    strs[3] = "How are you?";
    strs[4] = "Good";
    strs[5] = "All right";
    sep = " ";
    size = 0;
    while (size <= 6)
    {
        result = ft_strjoin(size, strs, sep);
        printf("size:%d %s\n", size, result);
        free(result);
        size++;
    }
}
