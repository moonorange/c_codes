
// ex00
#include <stdio.h>
int		main(void)
{
	int a = 1;
	printf("%d\n", a);
	ft_ft(&a);
	printf("%d\n", a);
}



// ex01
#include <stdio.h>
int		main(void)
{
	int a = 1;
	int* a1 = &a;
	int** a2 = &a1;
	int*** a3 = &a2;
	int**** a4 = &a3;
	int***** a5 = &a4;
	int****** a6 = &a5;
	int******* a7 = &a6;
	int******** a8 = &a7;
	int********* a9 = &a8;

	printf("%d\n", a);
	ft_ultimate_ft(a9);
	printf("%d\n", a);
}
// ex02
#include <stdio.h>
int		main(void)
{
	int a = 1;
	int b = 2;

	printf("%d %d\n", a, b);
	ft_swap(&a, &b);
	printf("%d %d\n", a, b);
}


// ex03
#include <stdio.h>
int		main(void)
{
	int a = 5;
	int b = 2;
	int div;
	int mod;

	ft_div_mod(a, b, &div, &mod);
	printf("%d / %d = %d, ...%d\n", a, b, div, mod);
}


// ex04
#include <stdio.h>
int		main(void)
{
	int a = 5;
	int b = 2;

	ft_ultimate_div_mod(&a, &b);
	printf(" %d,  %d\n", a, b);
}



// ex05
#include <stdio.h>
int		main(void)
{
	char string[] = "Hello World";
	printf("%s\n", string);
	ft_putstr(string);
    printf("\n");
}


// ex06
#include <stdio.h>
int     main(void)
{
    char string[12] = "Hello World";
    ft_strlen(string);
    printf("%d\n", ft_strlen(string));
}

    // #ex07
#include <stdio.h>

int     main(void)
{
    int tab[] = {1,2,3,4,5,6,7,8};
    int size = 8;
    int i = 0;
    int j = 0;
    while (i < size)
    {
        printf("%d\n", tab[i]);
        i++;
    }
    printf("rev:\n");
    ft_rev_int_tab(tab, size);
    while (j < size)
    {
        printf("%d\n", tab[j]);
        j++;
    }
}


// ex08
#include <stdio.h>
int main(void)
{
    int tab[] = {1,7,3,5,10,4,3};
    int size = 8;
    int i = 0;
    int j = 0;
     while (i < size)
    {
        printf("%d\n", tab[i]);
        i++;
    }
    ft_sort_int_tab(tab, size);
    printf("rev\n");
    while (j < size)
    {
        printf("%d\n", tab[j]);
        j++;
    }
}
