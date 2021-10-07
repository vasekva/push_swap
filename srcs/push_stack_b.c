#include "push_swap.h"

/*
 * rotate - <- (-1)
 * reverse_rotate - -> (+1)
 */
/*
int	define_index(t_stack *stack, int value)
{
	int max;
	int min;

	if (!stack)
		return (0);
	min = find_min_value(stack);
	max = find_max_value(stack);
	if (value > max)
	{
		printf("max\n");
		while (stack)
		{
			if (stack->value == max)
				return (stack->ind);
			stack = stack->next;
		}
	}
	else if (value < min)
	{
		printf("min\n");
		while (stack)
		{
			if (stack->value == min)
				return (stack->ind);
			stack = stack->next;
		}
	}
	else
	{
		printf("middle\n");
		while (stack->next)
		{
			if (value < stack->value)
			{
				printf("%d < %d\n", value, stack->value);
				if (stack->next)
				{
					//printf("NEXT: %d\n", tmp->value);
					if (value > stack->next->value)
					{
						printf("%d > %d\n", value, stack->next->value);
						return (stack->next->ind);
					}
				}
			}
			stack = stack->next;
		}
	}
	return (0);
}
*/
int	push_stack_b(t_stack **stack_a, t_stack **stack_b, int rotate_count_a, int rotate_count_b)
{
	int put_ind;
	int	number;

	number = get_nth(*stack_a, ft_abs(rotate_count_a))->value;
	put_ind = find_put_ind(*stack_b, number, 0);
	if (put_ind == 0)
	{
		if (number < (*stack_b)->value)
		{
			scroll_stacks(stack_a, stack_b, rotate_count_a, -1);
			push(stack_a, stack_b, "b", 1);
			rotate_count_b = 1;
		}
		else 		// если number - самое большое
		{
			scroll_to_past(stack_a, "a", rotate_count_a);
			push(stack_a, stack_b, "b", 1);
			rotate_count_b = 0;
		}
	}
	else
	{
		if (put_ind == -1)
		{
			scroll_to_past(stack_a, "a", rotate_count_a);
			push(stack_a, stack_b, "b", 1);
			rotate_count_b = -1;
		}
		else {
			if (put_ind < 0)
			{
				scroll_stacks(stack_a, stack_b, rotate_count_a, abs(put_ind) - 1);
			}
			else
			{
				scroll_stacks(stack_a, stack_b, rotate_count_a, (put_ind + 1) * (-1));
			}
			push(stack_a, stack_b, "b", 1);
			if (put_ind < 0)
			{
				rotate_count_b = put_ind;
			}
			else
			{
				rotate_count_b = put_ind + 1;
			}
		}
	}
	return (rotate_count_b);
}