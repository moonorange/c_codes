// ex00

#include <stdio.h>
#include <string.h>
int main(void)
{
    char *str1;
    char *str2;
    char *str3;

    str1 = "Hello";
    str2 = "Hello42";
    str3 = "42";
    printf("cfun: %d\n", strcmp(str1, str2));
    printf("mine: %d\n", ft_strcmp(str1, str2));
    printf("cfun: %d\n", strcmp(str1, str3));
    printf("mine: %d\n", ft_strcmp(str1, sr3));
}

// exo1
#include <stdio.h>
#include <string.h>
int main(void)
{
    char *str1;
    char *str2;
    char *str3;
    char *str4;
    char *str5;

    str1 = "Hello";
    str2 = "Hello42";
    str3 = "Gzzzzzz";
    str4 = "z";
    str5 = "He";
    printf("cfun: %d\n", strncmp(str1, str2, 3));
    printf("mine: %d\n", ft_strncmp(str1, str2, 3));
    printf("cfun: %d\n", strncmp(str1, str3, 4));
    printf("mine: %d\n", ft_strncmp(str1, str3, 4));
    printf("cfun: %d\n", strncmp(str1, str4, 5));
    printf("mine: %d\n", ft_strncmp(str1, str4, 5));
    printf("cfun: %d\n", strncmp(str1, str5, 5));
    printf("mine: %d\n", ft_strncmp(str1, str5, 5));
}

// ex02
#include <stdio.h>
#include <string.h>
int     main(void)
{
    char    dest[20] = "Hello";
    char    dest2[20] = "Hello";
    char    *src = " World";

    printf("cfunc: %s$\n", strcat(dest, src));
    printf("myfun: %s$\n", ft_strcat(dest2, src));
}

// ex03
#include <stdio.h>
#include <string.h>
int     main(void)
{
    char    dest[20] = "Hello";
    char    dest2[20] = "Hello";
    char    *src = " World";

    printf("cfunc: %s$\n", strncat(dest, src, 2));
    printf("myfun: %s$\n", ft_strncat(dest2, src, 2));
}

// ex04
#include <stdio.h>
#include <string.h>

int     main(int argc, char **argv)
{
    argc = 0;
    printf("cfun  : %s$\n", strstr(argv[1], argv[2]));
    printf("myfunc: %s$\n", ft_strstr(argv[1], argv[2]));
    printf("cfun  : %s$\n", strstr("Hello", "good bye"));
    printf("myfunc: %s$\n", ft_strstr("Hello", "good bye"));
    printf("cfun  : %s$\n", strstr("Hello", ""));
    printf("myfunc: %s$\n", ft_strstr("Hello", ""));
    printf("cfun  : %s$\n", strstr("", ""));
    printf("myfunc: %s$\n", ft_strstr("", ""));
    printf("cfun  : %s$\n", strstr("", "Hello"));
    printf("myfunc: %s$\n", ft_strstr("", "Hello"));
}


// ex05
#include <string.h>
#include <stdio.h>
int             main(void)
{
    char dest1[8] = "Hello";
    char dest2[8] = "Hello";
    char src[] = "0123";
    unsigned int size = 4;
    printf("myfunc: %u\n",ft_strlcat(dest1, src, size));
    printf("c func: %lu\n",strlcat(dest2, src, size));
    printf("myfunc: %s\n", dest1);
    printf("c func: %s\n",dest2);
    return (0);
}
