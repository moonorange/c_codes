int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	if (length == 0)
		return (0);
	return (((*f)(tab[0]) != 0 ? 1 : 0) + ft_count_if(tab + 1, length - 1, f));
}

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

    array = malloc(11 * sizeof(char *));
    array[0] = "a";
    array[1] = "a";
    array[2] = "a";
    array[3] = "b";
    array[4] = "a";
    array[5] = "b";
    array[6] = "a";
    array[7] = "a";
    array[8] = "a";
    array[9] = "a";
    array[10] = 0;
    printf("%d\n", ft_count_if(array,10, &is_a));
}
