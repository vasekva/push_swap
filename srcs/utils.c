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

void	scroll_to_past(t_stack **stack, char *stack_name, int rotate_count)
{
	if (rotate_count != 0)
	{
		if (rotate_count < 0)
			rotate(stack, stack_name, ft_abs(rotate_count));
		else
			reverse_rotate(stack, stack_name, ft_abs(rotate_count));
	}
}

void	scroll_stacks(t_stack **stack_a, t_stack **stack_b, int rotate_count_a, int rotate_count_b)
{

	if (rotate_count_a < 0 && rotate_count_b < 0)
	{
		while (rotate_count_a && rotate_count_b)
		{
			execute_two_cmds("rr", stack_a, stack_b, 1);
			++rotate_count_a;
			++rotate_count_b;
		}
	}
	else if (rotate_count_a > 0 && rotate_count_b > 0)
	{
		while (rotate_count_a && rotate_count_b)
		{
			execute_two_cmds("rrr", stack_a, stack_b, 1);
			--rotate_count_a;
			--rotate_count_b;
		}
	}
	scroll_to_past(stack_a, "a", rotate_count_a);
	scroll_to_past(stack_b, "b", rotate_count_b);
}