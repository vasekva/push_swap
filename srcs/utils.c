#include "push_swap.h"

/**
 * Функция возвращает модуль
 * полученного числа.
 */
int	ft_abs(int number)
{
	if (number < 0)
		return (-number);
	else
		return (number);
}

void	print_action_message(char *stack_name, char *action)
{
	write(1, action, ft_strlen(action));
	if (stack_name)
		write(1, stack_name, ft_strlen(stack_name));
	write(1, "\n", 1);
}

void	arr_free(char **array)
{
	int	ind;

	ind = 0;
	if (array != NULL)
	{
		while (array[ind])
		{
			if (array[ind] != NULL)
			{
				free(array[ind]);
				array[ind] = NULL;
			}
			ind++;
		}
		free(array);
		array = NULL;
	}
}