#include <unistd.h>

int		is_space(char c)
{
	return (c == ' ' || c == '\t');
}

void	ft_first_word(char *str)
{
	int		f_space_num;
	int 	word_num;

	f_space_num = 0;
	while (is_space(str[f_space_num]))
		f_space_num++;
	word_num = f_space_num;
	while (str[word_num])
	{
		if (is_space(str[word_num]))
			break ;
		word_num++;
	}
	if (str != '\0')
		write(1, str + f_space_num, word_num - f_space_num);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		ft_first_word(argv[1]);
	write(1, "\n", 1);
}
