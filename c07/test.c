#include <stdlib.h>

int		ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}

char	*ft_strcpy(char *dest, char *src)
{
	int idx;

	idx = 0;
	while (src[idx] != '\0')
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}

int		cal_sum_len(char **strs, int size, int sep_len)
{
	int	sum_len;
	int	idx;

	sum_len = 0;
	idx = 0;
	while (idx < size)
	{
		sum_len += ft_strlen(strs[idx]);
		sum_len += sep_len;
		idx++;
	}
	sum_len -= sep_len;
	return (sum_len);
}

void	concat_strs(int size, char **strs, char *str, char *sep)
{
	int		idx;

	idx = 0;
	while (idx < size)
	{
		ft_strcpy(str, strs[idx]);
		str += ft_strlen(strs[idx]);
		if (idx < size - 1)
		{
			ft_strcpy(str, sep);
			str += ft_strlen(sep);
		}
		idx++;
	}
	*str = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		sum_len;
	char	*str;

	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	sum_len = cal_sum_len(strs, size, ft_strlen(sep));
	str = (char *)malloc((sum_len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	concat_strs(size, strs, str, sep);
	return (str);
}

#include <stdio.h>
int     main(void)
{
    int     size;
    char    **strs;
    char    *sep;
    char    *result;

    strs = (char**)malloc(6 * sizeof(strs));
    strs[0] = "Hello";
    strs[1] = "World";
    strs[2] = "42";
    strs[3] = "How are you?";
    strs[4] = "Good";
    strs[5] = "All right";
    sep = " ";
    size = 0;
    while (size <= 6)
    {
        result = ft_strjoin(size, strs, sep);
        printf("size:%d, %s\n", size, result);
        free(result);
        size++;
    }
}
