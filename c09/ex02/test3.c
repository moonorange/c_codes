#include <stdlib.h>

int		is_pattern(char c, char *pattern)
{
	int i;

	i = 0;
	while (pattern[i])
	{
		if (pattern[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		is_pattern_at(char *src, char *pattern, int i)
{
	if (src[i - 1] && src[i + 1] &&
			!is_pattern(src[i + 1], pattern) && is_pattern(src[i], pattern))
		return (1);
	return (0);
}

int		count_splits(char *src, char *pattern)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (is_pattern(src[i], pattern))
		i++;
	if (!src[i])
		return (0);
	while (src[i])
	{
		if (is_pattern_at(src, pattern, i++))
			res++;
	}
	return (res + 1);
}

int		len(char *str, char *charset, int j)
{
	int x;

	x = 0;
	while (!is_pattern_at(str, charset, j + x) && str[j + x])
		x++;
	return (x);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		k;
	char	**res;

	res = malloc(sizeof(char*) * (count_splits(str, charset) + 1));
	i = 0;
	j = 0;
	while (i < count_splits(str, charset))
	{
		k = 0;
		while (is_pattern(str[j], charset))
			j++;
		res[i] = malloc(sizeof(char) * (len(str, charset, j) + 1));
		while (!is_pattern_at(str, charset, j) && str[j])
		{
			if (!is_pattern(str[j], charset))
				res[i][k++] = str[j];
			j++;
		}
		j += 1;
		res[i++][k] = '\0';
	}
	res[i] = 0;
	return (res);
}

#include <stdio.h>
int		main(int argc, char **argv)
{
	int		idx;
	char	**array;

	argc = argc + 0;
	array = ft_split(argv[1], argv[2]);
	idx = 0;
	while (array[idx])
	{
		printf("arraay[%d]: %s\n", idx, array[idx]);
		idx++;
	}
}
