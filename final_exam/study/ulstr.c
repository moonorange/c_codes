#include <unistd.h>

int     is_upper(char ch)
{
    return ('A' <= ch && ch <= 'Z');
}


int     is_lower(char ch)
{
    return ('a' <= ch && ch <= 'z');
}

// void    ft_putstr(char *str)
// {
//     while (*str)
//     {
//         write(1, str, 1);
//         str++;
//     }
// }

void    ulstr(char *str)
{
    int     idx;

    idx = 0;
    while(str[idx])
    {
        if (is_upper(str[idx]))
            str[idx] += 32;
        else if (is_lower(str[idx]))
            str[idx] -= 32;
        write(1, &str[idx], 1);
        idx++;
    }
}

int     main(int argc, char **argv)
{
    if (argc == 2)
        ulstr(argv[1]);
    write(1, "\n", 1);
}
