/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtomishi <xxx@xxx>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 11:27:14 by rtomishi          #+#    #+#             */
/*   Updated: 2020/09/24 17:57:45 by rtomishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		isin_char(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i += 1;
	}
	return (0);
}

void	input_box(char *str, char **box, int n, int i)
{
	int j;

	box[i] = (char *)malloc(sizeof(char) + (n + 1));
	j = 0;
	while (str[j] != '\0' && j < n)
	{
		box[i][j] = str[j];
		j += 1;
	}
	box[i][j] = '\0';
}

void	split_str(char *str, char *charset, char **box)
{
	int	st;
	int	p;
	int	i;

	st = 0;
	p = 0;
	i = 0;
	while (str[p] != '\0')
	{
		if (isin_char(str[p], charset) == 1 && p == st)
			st += 1;
		else if (isin_char(str[p], charset) == 1 && p != st)
		{
			input_box(&str[st], box, p - st, i);
			st = p + 1;
			i += 1;
		}
		p += 1;
	}
	if (st < p)
	{
		input_box(&str[st], box, p - st, i);
		i += 1;
	}
	box[i] = NULL;
}

int		sep_cnt(char *str, char *charset)
{
	int		i;
	int		miss_flag;
	int		cnt;

	i = 0;
	miss_flag = 1;
	cnt = 0;
	while (isin_char(str[i], charset) == 1)
		i += 1;
	while (str[i] != '\0')
	{
		if (isin_char(str[i], charset) == 1)
		{
			if (miss_flag == 1)
				cnt += 1;
			miss_flag = 0;
		}
		else
			miss_flag = 1;
		i += 1;
	}
	return (cnt);
}

char	**ft_split(char *str, char *charset)
{
	int		cnt;
	char	**box;

	if (!str)
		return (0);
	cnt = 0;
	cnt = sep_cnt(str, charset);
	box = (char **)malloc(sizeof(char *) * (cnt + 1 + 1));
	if (box == NULL)
		return (0);
	split_str(str, charset, box);
	return (box);
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
