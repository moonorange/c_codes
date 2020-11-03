#include <stdio.h>
int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int		idx;
	int		sorted;

    sorted = 1;
    idx = 0;
    while (idx < length - 1)
    {
        if ((*f)(tab[idx], tab[idx + 1]) > 0)
        {
            sorted = 0;
            break ;
        }
        idx++;
    }
    if (sorted == 0)
    {
        idx = 0;
        while (idx < length - 1)
        {
            if ((*f)(tab[idx], tab[idx + 1]) < 0)
                return (0);
            idx++;
        }
    }
	return (1);
}

#include <stdlib.h>
#include <stdio.h>

int		ft_comp(int a, int b)
{
    return (a - b);
}

int		main(void)
{
	static int	tab[] = { 8,9,8,7,6,5,4,4,3,3,2,2,1 };
	int			idx;
	int			length;

	length = 13;
	idx = 0;
	printf("ft_is_sort(): %d\n", ft_is_sort(tab, length, &ft_comp));
}
