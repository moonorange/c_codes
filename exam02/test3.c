#include <stdbool.h>

bool	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\r' || c == '\f');
}

bool	is_sign(char c)
{
	return (c == '-' || c == '+');
}

bool	is_number(char c)
{
	return (c >= '0' && c <= '9');
}

int		ft_atoi(const char *str)
{
	int	ans;
	int	sign;

	sign = 1;
	while (is_space(*str))
		str++;
	if (is_sign(*str))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	ans = 0;
	while (is_number(*str))
	{
		ans *= 10;
		ans += *str - '0';
		str++;
	}
	return (ans * sign);
}

#include <stdio.h>
#include <stdlib.h>
int     main(void)
{
    printf("%d\n", ft_atoi("-+483648"));
    printf("%d\n", atoi("--483648"));
}
