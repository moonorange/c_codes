#include <unistd.h>

void    rev_print(char *str)
{
    int     len;

    len = 0;
    while (str[len])
        len++;
    while (0 <= len - 1)
    {
        write(1, &str[len - 1], 1);
        len--;
    }
}

int     main(void)
{
    rev_print("Hello");
    write(1, "\n", 1);
}
