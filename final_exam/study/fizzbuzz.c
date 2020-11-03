#include <unistd.h>

void    ft_putnbr(int num)
{
    char ch_num;

    if (num > 9)
        ft_putnbr(num / 10);
    ch_num = num % 10 + '0';
    write(1, &ch_num, 1);
}

int     main(void)
{
    int     idx;

    idx = 1;
    while (idx <= 100)
    {
        if (idx % 3 == 0 && idx % 5 == 0)
            write(1, "fizzbuzz", 8);
        else if(idx % 3 == 0)
            write(1, "fizz", 4);
        else if(idx % 5 == 0)
            write(1, "buzz", 4);
        else
            ft_putnbr(idx);
        write(1, "\n", 1);
        idx++;
    }
}
