#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	ft_swap(char **a, char **b)
{
	char *c;

	c = *a;
	*a = *b;
	*b = c;
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char*)s1 - *(unsigned char*)s2);
}

void	ft_sort_string_tab(char **tab)
{
	int		index;
	int		size;
	bool	swapped;

	size = 0;
	while (tab[size])
		size++;
	while (true)
	{
		index = 0;
		swapped = false;
		while (index < size - 1)
		{
			if (ft_strcmp(tab[index], tab[index + 1]) > 0)
			{
				ft_swap(&tab[index], &tab[index + 1]);
				swapped = true;
			}
			index++;
		}
		if (!swapped)
			break ;
	}
}

int		main(void)
{
	int		index;
	char	**tab;

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
    tab[12] = NULL;
	index = 0;
	while (tab[index])
	{
		printf("tab[%d] <@ %p> = $%s$\n", index, tab + index, tab[index]);
		index++;
	}
	ft_sort_string_tab(tab);
	printf("\n");
	index = 0;
	while (tab[index])
	{
		printf("tab[%d] <@ %p> = $%s$\n", index, tab + index, tab[index]);
		index++;
	}
}
