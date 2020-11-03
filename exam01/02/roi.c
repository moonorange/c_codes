#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		is_lower(char c)
{
	if ('a' <= c && c <= 'z')
		return (1);
	return (0);
}

int		is_upper(char c)
{
	if ('A' <= c && c <= 'Z')
		return (1);
	return (0);
}

char	foward_13(char c)
{
	unsigned char	tmp;
	char	last_al;

	if (is_upper(c))
		last_al = 'Z';
	else
		last_al = 'z';
	tmp = c + 13;
	if (last_al < tmp)
		tmp -= 26;
	return (tmp);
}

void	rot_13(char *str)
{
	while (*str)
	{
		if (is_lower(*str) || is_upper(*str))
			*str = foward_13(*str);
		ft_putchar(*str);
		str++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		rot_13(argv[1]);
	ft_putchar('\n');
}
