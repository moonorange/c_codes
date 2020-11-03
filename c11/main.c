// ex00
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

int		main(void)
{
	int	idx;
	int	tab[] = { 1,2,3,4,5,6,7,8,9,10 };
	int	length;

	length = 10;
	ft_foreach(tab, length, &ft_putnbr);
}



// ex01
#include <stdio.h>
int ft_put_num(int num)
{
    return (num);
}

#include <stdlib.h>
int main(void)
{
    int idx = 0;
    int *tab;
    int len = 5;
    int *array;

    tab = malloc(len * sizeof(int));
    while (idx < len)
    {
        tab[idx] = idx;
        idx++;
    }
    array = ft_map(tab, len, &ft_put_num);
    idx = 0;
    while (idx < len)
    {
        printf("idx: %d array %d\n", idx, array[idx]);
        idx++;
    }
}

// ex02
int is_a(char *str)
{
    if (*str == 'a')
        return (1);
    return (0);
}

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char    **array;

    array = malloc(5 * sizeof(char *));
    array[0] = "c";
    array[1] = "d";
    array[2] = "b";
    array[3] = "b";
    array[4] = 0;
    printf("%d\n", ft_any(array, &is_a));
}


int is_a(char *str)
{
    if (*str == 'a')
        return (1);
    return (0);
}


// ex03
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char    **array;

    array = malloc(5 * sizeof(char *));
    array[0] = "a";
    array[1] = "a";
    array[2] = "a";
    array[3] = "b";
    array[4] = 0;
    printf("%d\n", ft_count_if(array, &is_a));
}



// ex04
#include <stdlib.h>
#include <stdio.h>

int		ft_comp(int a, int b)
{
    return (a - b);
}

int		main(void)
{
	static int	tab[] = { 1, 3, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10 };
	int			idx;
	int			length;

	length = 13;
	idx = 0;
	printf("ft_is_sort(): %d\n", ft_is_sort(tab, length, &ft_comp));
}


// ex06
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int     main(void)
{
    int     idx = 0;
    char    **tab;

    tab = malloc(13 * sizeof(char *));
    tab[0] = strdup("Hello");
    tab[1] = strdup("World");
    tab[2] = strdup("a");
    tab[3] = strdup("aa");
    tab[4] = strdup("a42");
    tab[5] = strdup("ab");
    tab[6] = strdup("z");
    tab[7] = strdup("~");
    tab[8] = strdup(" ");
    tab[9] = strdup("A");
    tab[10] = strdup("-");
    tab[11] = strdup("aaaaa");
    tab[12] = 0;
    ft_sort_string_tab(tab);
    printf("\n");
    while (tab[idx])
    {
        printf("tab[%d] %s\n", idx, tab[idx]);
        idx++;
    }
}



// ex07
int     ft_strcmp(char *s1, char *s2)
{
    unsigned char *us1;
    unsigned char *us2;

    us1 = (unsigned char*)s1;
    us2 = (unsigned char*)s2;
    while (*us1 != '\0' && *us1 == *us2)
    {
        us1++;
        us2++;
    }
    return (*us1 - *us2);
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int     main(void)
{
    int     idx = 0;
    char    **tab;

    tab = malloc(13 * sizeof(char *));
    tab[0] = strdup("Hello");
    tab[1] = strdup("World");
    tab[2] = strdup("a");
    tab[3] = strdup("aa");
    tab[4] = strdup("a42");
    tab[5] = strdup("ab");
    tab[6] = strdup("z");
    tab[7] = strdup("~");
    tab[8] = strdup(" ");
    tab[9] = strdup("A");
    tab[10] = strdup("-");
    tab[11] = strdup("aaaaa");
    tab[12] = 0;
    ft_advanced_sort_string_tab(tab, &ft_strcmp);
    printf("\n");
    while (tab[idx])
    {
        printf("tab[%d] %s\n", idx, tab[idx]);
        idx++;
    }
}
