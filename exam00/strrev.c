#include <stdio.h>

int		ft_str_length(char *str)
{
	int index;

	index = 0;
	while (str[index++] != '\0');
	return (index-1);
}

char	*ft_strrev(char *str)
{
	int size;
	int index;
	char tmp;

	size = ft_str_length(str);
	index = 0;
    printf("%d\n", size / 2);
	while (index != size / 2)
	{
		tmp = str[index];
		str[index] = str[size - 1 - index];
		str[size - 1 - index] = tmp;
        printf("%d\n", index);
		index++;
	}
	printf("%s\n", str);
}

int main(void)
{
    char str[] = "hellog";
    ft_strrev(str);
    return (0);
}
