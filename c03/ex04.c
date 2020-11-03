char    *ft_strstr(char *str, char *to_find)
{
    int s_id;
    int f_id;

    s_id = 0;
    f_id = 0;
    if (to_find[f_id] == '\0')
        return (str);
    while (str[s_id])
    {
        f_id = 0;
        while (str[s_id + f_id] == to_find[f_id] && str[s_id + f_id])
        {
            f_id++;
            if (to_find[f_id] == '\0')
                return (&str[s_id]);
        }
        s_id++;
    }
    return (0);
}

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
