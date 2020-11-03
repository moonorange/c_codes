#include <stdlib.h>
#include <stdio.h>

int		is_in_charset(char ch, char *charset)
{
	while (*charset != '\0')
	{
		if (*charset == ch)
			return (1);
		charset++;
	}
	if (*charset == '\0')
		return (ch == '\0');
	return (0);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int idx;

	idx = 0;
	while (idx < n && src[idx] != '\0')
	{
		dest[idx] = src[idx];
		idx++;
	}
	while (idx < n)
	{
		dest[idx] = '\0';
		idx++;
	}
	return (dest);
}

int		count_sep(char *str, char *charset)
{
	int		count;
	char	*behind;
	char	*set_p;

	count = 0;
	behind = str;
	set_p = str;
	while (1)
	{
		if (is_in_charset(*str, charset))
			set_p = str;
		if (set_p - behind > 1)
			count++;
		if (*str == '\0')
			break ;
		behind = set_p;
		str++;
	}
	return (count);
}

void		make_array(char **new_array, char *behind, int size, char *charset)
{
	if (is_in_charset(behind[0], charset))
	{
		behind++;
		size--;
	}
	*new_array = (char *)malloc((size + 1) * sizeof(char));
	ft_strncpy(*new_array, behind, size);
	(*new_array)[size] = '\0';
}

char	**ft_split(char *str, char *charset)
{
	int		idx;
	int		size;
	char	*behind;
	char	*set_p;
	char	**array;

	array = (char **)malloc((count_sep(str, charset) + 1) * sizeof(char *));
	idx = 0;
	behind = str;
	set_p = str;
	while (1)
	{
		if (is_in_charset(*str, charset))
			set_p = str;
		if ((size = set_p - behind) > 1)
			make_array(&array[idx++], behind, size, charset);
		if (*str == '\0')
			break ;
		behind = set_p;
		str++;
	}
	array[idx] = 0;
	return (array);
}

#include <stdio.h>
int		main(int argc, char **argv)
{
	int		idx;
	char	**array;

	argc = 0;
	array = ft_split(argv[1], argv[2]);
	idx = 0;
	while (array[idx])
	{
		printf("array[%d]: %s\n", idx, array[idx]);
		idx++;
	}
}
