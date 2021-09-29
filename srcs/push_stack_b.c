#include "push_swap.h"

void	push_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	int put_ind;
	int	number;

	number = (*stack_a)->value;
	put_ind = find_put_ind(*stack_b, number);
	//printf("PUT: %d after %d\n", number, put_ind);
	if (put_ind == 0)
	{
		if (number < (*stack_b)->value)
		{
			rotate(stack_b, "b", 1);
			push(stack_a, stack_b, "b", 1);
			reverse_rotate(stack_b, "b", 1);
		}
		else 		// если number - самое большое
			push(stack_a, stack_b, "b", 1);
	}
	else
	{
		if (put_ind == -1)
		{
			push(stack_a, stack_b, "b", 1);
			rotate(stack_b, "b", 1);
		}
		else {
			//printf("else\n");
			if (put_ind < 0)
				reverse_rotate(stack_b, "b", abs(put_ind) - 1);
			else
				rotate(stack_b, "b", put_ind + 1);
			push(stack_a, stack_b, "b", 1);
			if (put_ind < 0)
				rotate(stack_b, "b", abs(put_ind));
			else
				reverse_rotate(stack_b, "b", abs(put_ind) + 1);
		}
	}
}