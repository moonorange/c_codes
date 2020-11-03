// #ex00
#include <stdio.h>
#include <string.h>
int     main(void)
{
    char src[] = "Hello World";
    char dest[12];

strcpy(dest, src);
    printf("strcpy: %s\n", dest);
printf("myfunc: %s\n", ft_strcpy(dest, src));
}

// ex01
#include <stdio.h>
#include <unistd.h>
#include <string.h>
int     main(void)
{
    char dest[16];
    char src[] = "Hello world";
    int i = 0;
    int size;


    strncpy(dest, src, 6);
    printf("lib : %s\n", dest);
    ft_strncpy(dest, src, 6);
    printf("myft: %s\n", dest);
    strncpy(dest, src, 16);
    printf("lib : %s\n", dest);
    ft_strncpy(dest, src, 16);
    printf("myft: %s\n", dest);
}

// exo2
#include <stdio.h>

int     main(void)
{
    char all_alpha[] = "Hello";
    char false_alpha[] = "Hello7";
    char false_alpha2[] = "Hello ";
    printf("true: %d\n", ft_str_is_alpha(all_alpha));
    printf("false: %d\n", ft_str_is_alpha(false_alpha));
    printf("false: %d\n", ft_str_is_alpha(false_alpha2));
}

// ex03
#include <stdio.h>

int     main(void)
{
    char numeric[] = "580185039";
    char isnt_numeric[] = "123js";
    char space[] = "13243 ";

    printf("true: %d\n", ft_str_is_numeric(numeric));
    printf("false: %d\n", ft_str_is_numeric(isnt_numeric));
    printf("false: %d\n", ft_str_is_numeric(space));
}

// ex04
#include <stdio.h>

int     main(void)
{
    char true_str[] = "hello";
    char false_str[] = "Hello";
    char void_str[] = "";
    printf("true: %d\n", ft_str_is_lowercase(true_str));
    printf("false: %d\n", ft_str_is_lowercase(false_str));
    printf("true: %d\n", ft_str_is_lowercase(void_str));
}

// ex05
#include <stdio.h>

int     main(void)
{
    char true_str[] = "HELLO";
    char false_str[] = "Hello";
    char void_str[] = "";
    printf("true: %d\n", ft_str_is_uppercase(true_str));
    printf("false: %d\n", ft_str_is_uppercase(false_str));
    printf("true: %d\n", ft_str_is_uppercase(void_str));
}

// ex06
#include <stdio.h>
int     main(void)
{
    char true_str[] = " Hello~";
    char false_str[] = "\1";

    printf("true: %d\n", ft_str_is_printable(true_str));
    printf("false: %d\n", ft_str_is_printable(false_str));

    printf("%s\n", true_str);
    printf("%s\n", false_str);
}

// ex07
#include <stdio.h>

int     main(void)
{
    char test_str[] = "hello";
    char test_str2[] = "Hello";
    char test_str3[] = "12345";
    printf("%s\n", ft_strupcase(test_str));
    printf("%s\n", ft_strupcase(test_str2));
    printf("%s\n", ft_strupcase(test_str3));
}

// ex08
#include <stdio.h>

int     main(void)
{
    char test_str[] = "HELLO";
    char test_str2[] = "Hello";
    char test_str3[] = "12345";
    printf("%s\n", ft_strlowcase(test_str));
    printf("%s\n", ft_strlowcase(test_str2));
    printf("%s\n", ft_strlowcase(test_str3));
}

// ex09
#include <stdio.h>
int     main(void)
{
    char test[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
    char test2[] = "bsSANWAesjef";
    char test3[] = "12shr";

    printf("test: %s\n", ft_strcapitalize(test));
    printf("test2: %s\n", ft_strcapitalize(test2));
    printf("test3: %s\n", ft_strcapitalize(test3));
}

// ex10
#include <string.h>
#include <stdio.h>
int main(void)
{
    char dest[20];
    char src[] = "Hello";
    char src2[] = "Hello World";
    char src3[] = "";

    printf("buit-in:%d  mine:%lu\n", ft_strlcpy(dest, src, 5), strlcpy(dest, src, 5));
    printf("buit-in:%d  mine:%lu\n", ft_strlcpy(dest, src2, 5), strlcpy(dest, src2, 5));
    printf("buit-in:%d  mine:%lu\n", ft_strlcpy(dest, src3, 5), strlcpy(dest, src3, 5));
}

// ex11
#include <stdio.h>

void    ft_putstr_non_printable(char *str);

int main(void)
{
    printf("%s\n", "Coucou\ntu vas bien ?");
    ft_putstr_non_printable("Coucou\ntu vas bien ?");
}
