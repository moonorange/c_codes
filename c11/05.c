(*operations[5])(int, int) = {
			&ft_add,
			&ft_minus,
			&ft_devide,
			&ft_multiply,
			&ft_modulo
	};
	int			ans;
	int			idx;

	ans = 0;
	idx = 0;
	while (idx < 5)
	{
		if (operator == operators[idx])
		{
			ans = (operations[idx])(f_num, s_num);
			break ;
		}
		idx++;
	}
	ft_number_write(ans);
	ft_str_write("\n");
