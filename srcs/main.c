#include "push_swap.h"

int	is_int_num(char *str)
{
	int	i;
	long long	number;

	i = -1;
	number = 0;
	// проверка на то, что строка - число
	while (str[++i])
	{
		if (i == 0 && str[i] == '-')
			continue ;
		if (!ft_isdigit(str[i]))
		{
			exception(NOTDIGIT);
		}
	}
	number = ft_atoi(str);
	if (number > 2147483647 || number < -2147483648)
		exception(OVERFLOW);
	return ((int)number);
}

int	parse_parameters(int argc, char **argv)
{
	int	i;

	i = 1;
	// проверка валидности чисел в массиве
	while (argv[i])
	{
		is_int_num(argv[i]);
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc >= 2)
	{
		parse_parameters(argc, argv);
		printf("Hello, World!\n");
	}
	else
		exception(FEWPARAMS);
	return 0;
}
