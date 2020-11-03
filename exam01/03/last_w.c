#include <unistd.h>
#include <stdio.h>

int		is_space(char c)
{
	return (c == ' ' || c == '\t');
}

void	ft_lastword(char *src)
{
	char	*last_w;
	int		is_word_sep = 0;

	last_w = src;
	while (*src)
	{
		if (is_space(*src) && !is_word_sep)
			is_word_sep = 1;
		if (!is_space(*src) && is_word_sep)
		{
			is_word_sep = 0;
			last_w = src;
		}
		src++;
	}

	while (*last_w)
	{
		if (is_space(*last_w))
			break ;
		write(1, last_w, 1);
		last_w++;
	}
}

int		main(int	argc, char	**argv)
{
	if (argc == 2)
		ft_lastword(argv[1]);
	write(1, "\n", 1);
}
