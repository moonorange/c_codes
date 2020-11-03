#include <stdlib.h>

int     ft_strlen(char *str)
{
    int     idx;

    idx = 0;
    while (str[idx])
        idx++;
    return (idx);
}

#include <stdio.h>
char    *ft_strdup(char *src)
{
    int     idx;
    char    *dest;

    dest = (char *)malloc(ft_strlen(src) * sizeof(char) + 1);
    if (dest == NULL)
        return (NULL);
    idx = 0;
    while (src[idx])
    {
        dest[idx] = src[idx];
        idx++;
    }
    dest[idx] = '\0';
    return (dest);
}

#include <stdio.h>
#include <string.h>
int     main(void)
{
    printf("%s\n", ft_strdup("Hello"));
    printf("%s\n", strdup("Hello"));
    printf("%s\n", ft_strdup("Hello World"));
    printf("%s\n", strdup("Hello World"));
    printf("%s\n", ft_strdup("gajkn24 kwen 2 3%$&"));
    printf("%s\n", strdup("gajkn24 kwen 2 3%$&"));
}
