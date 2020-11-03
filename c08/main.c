
// ex01
#include "ft_boolean.h"
void ft_putstr(char *str)
{
    while (*str)
        write(1, str++, 1);
}

t_bool ft_is_even(int nbr)
{
    return ((EVEN(nbr)) ? TRUE : FALSE);
}

int main(int argc, char **argv)
{
    (void)argv;
    if (ft_is_even(argc - 1) == TRUE)
        ft_putstr(EVEN_MSG);
    else
        ft_putstr(ODD_MSG);
    return (SUCCESS);
}



// ex02
#include "ft_abs.h"
#include <stdio.h>

int     main(void)
{
    int num;

    num = -2;
    while (num < 3)
    {
        printf("%d\n", ABS(num));
        num++;
    }
}


// ex03
#include "ft_point.h"
void set_point(t_point *point)
{
    point->x = 42;
    point->y = 21;
}
int main(void)
{
    t_point point;
    set_point(&point);
    return (0);
}


// ex04
#include <stdio.h>
int                 main(int argc, char **argv)
{
    int                 idx;
    struct s_stock_str  *structs;

    structs = ft_strs_to_tab(argc, argv);
    idx = 0;
    while (idx < argc)
    {
        printf("size: %d\n", structs[idx].size);
        printf("str: %s\n", structs[idx].str);
        printf("copy: %s\n", structs[idx].copy);
        printf("\n");
        idx++;
    }
}

// header file
#ifndef FT_STOCK_STR_H
# define FT_STOCK_STR_H

typedef struct  s_stock_str
{
    int         size;
    char        *str;
    char        *copy;
}    t_stock_str;

#endif



// ex05
int main(int argc, char **argv)
{
    ft_show_tab(ft_strs_to_tab(argc, argv));
}
