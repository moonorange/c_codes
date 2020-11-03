#include <stdlib.h>
#include <stdio.h>

int		is_in_charset(char ch, char *charset)
{
	int idx;

	idx = 0;
	while (charset[idx])
	{
		if (charset[idx] == ch)
			return (1);
		idx++;
	}
	return (0);
}

int		is_in_charset_at(char *str, char *charset, int idx)
{
	if (str[idx - 1] &&
		str[idx + 1] &&
		!is_in_charset(str[idx + 1], charset) &&
		is_in_charset(str[idx], charset))
		return (1);
	return (0);
}

int		count_size(char *str, char *charset)
{
	int idx;
	int sep_num;

	idx = 0;
	sep_num = 0;
	while (is_in_charset(str[idx], charset))
		idx++;
	if (!str[idx])
		return (0);
	while (str[idx])
	{
		if (is_in_charset_at(str, charset, idx++))
			sep_num++;
	}
	return (sep_num + 1);
}

int		ft_strlen(char *str, char *charset, int s_id)
{
	int len;

	len = 0;
	while (!is_in_charset_at(str, charset, s_id + len) &&
			str[s_id + len])
		len++;
	return (len);
}

char	**ft_split(char *str, char *charset)
{
	int		size;
	int		s_id;
	int		len;
	char	**arrays;

	arrays = malloc(sizeof(char*) * (count_size(str, charset) + 1));
	size = 0;
	s_id = 0;
	while (size < count_size(str, charset))
	{
		len = 0;
		while (is_in_charset(str[s_id], charset))
			s_id++;
		arrays[size] = malloc(sizeof(char) * (ft_strlen(str, charset, s_id) + 1));
		while (!is_in_charset_at(str, charset, s_id) && str[s_id])
		{
			if (!is_in_charset(str[s_id], charset))
			arrays[size][len++] = str[s_id];
			s_id++;
		}
		s_id += 1;
		arrays[size++][len] = '\0';
	}
	arrays[size] = 0;
	return (arrays);
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
		printf("array[%d]: %s\n", idx, array[idx]);
		idx++;
	}
}
