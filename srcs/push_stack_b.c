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
int	push_stack_b(t_stack **stack_a, t_stack **stack_b, int rotate_count)
{
	int put_ind;
	int	number;

	number = (*stack_a)->value;
	put_ind = find_put_ind(*stack_b, number, 0);
	if (put_ind == 0)
	{
		if (number < (*stack_b)->value)
		{
			rotate(stack_b, "b", 1);
			push(stack_a, stack_b, "b", 1);
			rotate_count = 1;
		}
		else 		// если number - самое большое
		{
			push(stack_a, stack_b, "b", 1);
			rotate_count = 0;
		}
	}
	else
	{
		if (put_ind == -1)
		{
			push(stack_a, stack_b, "b", 1);
			rotate_count = -1;
		}
		else {
			if (put_ind < 0)
				reverse_rotate(stack_b, "b", abs(put_ind) - 1);
			else
				rotate(stack_b, "b", put_ind + 1);
			push(stack_a, stack_b, "b", 1);
			if (put_ind < 0)
			{
				rotate_count = put_ind;
			}
			else
			{
				rotate_count = put_ind + 1;
			}
		}
	}
	return (rotate_count);
}