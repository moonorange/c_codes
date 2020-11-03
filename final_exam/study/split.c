#include <stdlib.h>

int		ft_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\v' || c == '\f'
			|| c == '\n' || c == '\r');
}

void	make_array(char *str, char **strs_array, int str_len, int idx)
{
	int str_i;

	strs_array[idx] = (char *)malloc((str_len + 1) * sizeof(char));
	str_i = 0;
	while (str_i < str_len)
	{
		strs_array[idx][str_i] = str[str_i];
		str_i++;
	}
	strs_array[idx][str_i] = '\0';
}

void	split_strs(char *str, char **strs_array)
{
	int	behind;
	int	forward;
	int	idx;

	behind = 0;
	forward = 0;
	idx = 0;
	while (str[forward] != '\0')
	{
		if (ft_is_space(str[forward]) && forward == behind)
			behind++;
		else if (ft_is_space(str[forward]) && forward != behind)
		{
			make_array(&str[behind], strs_array, forward - behind, idx);
			behind = forward + 1;
			idx++;
		}
		forward++;
	}
	if (behind < forward)
	{
		make_array(&str[behind], strs_array, forward - behind, idx);
		idx++;
	}
	strs_array[idx] = 0;
}

int		count_sep_num(char *str)
{
	int		idx;
	int		cons;
	int		sep_num;

	idx = 0;
	cons = 1;
	sep_num = 0;
	while (ft_is_space(str[idx]))
		idx++;
	while (str[idx])
	{
		if (ft_is_space(str[idx]))
		{
			if (cons != 1)
				sep_num++;
			cons = 1;
		}
		else
			cons = 0;
		idx++;
	}
	return (sep_num);
}

char	**ft_split(char *str)
{
	int		sep_num;
	char	**strs_array;

	if (!str)
		return (0);
	sep_num = 0;
	sep_num = count_sep_num(str);
	strs_array = (char **)malloc(sizeof(char *) * (sep_num + 2));
	if (!strs_array)
		return (0);
	split_strs(str, strs_array);
	return (strs_array);
}


#include <stdio.h>
int		main(int argc, char **argv)
{
	int		idx;
	char	**array;

	argc = argc + 0;
	array = ft_split(argv[1]);
	idx = 0;
	while (array[idx])
	{
		printf("array[%d]: %s\n", idx, array[idx]);
		idx++;
	}
}
