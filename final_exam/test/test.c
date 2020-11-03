#include <unistd.h>

void    ft_putstr(char *str)
{
    int     idx;

    idx = 0;
    while (str[idx])
    {
        write(1, &str[idx], 1);
        idx++;
    }
}

int     main(int argc, char **argv)
{
    if (1 < argc)
        ft_putstr(argv[argc - 1]);
    write(1, "\n", 1);
}
