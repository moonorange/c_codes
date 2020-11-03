void	ft_foreach(int *tab, int length, void (*f)(int))
{
	if (length <= 0)
		return ;
	(*f)(tab[0]);
	ft_foreach(tab + 1, length - 1, f);
}

#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putnbr(int nb)
{
    if (0 <= nb && nb < 10)
    {
        ft_putchar(nb + '0');
    }
    else if (10 <= nb)
    {
        ft_putnbr(nb / 10);
        ft_putchar(nb % 10 + '0');
    }
    else if (nb == -2147483648)
    {
        ft_putnbr(nb / 10);
        ft_putchar('8');
    }
    else
    {
        ft_putchar('-');
        ft_putnbr(-nb);
    }
}

int     main(void)
{
    int tab[] = {1,2,3,50,60,4,0};
    ft_foreach(tab, 7, &ft_putnbr);
}
