#include "push_swap.h"

void	put_past_pointers(t_stack *stack)
{
	if (!stack)
		return;
	stack->past = NULL;
	while (stack->next)
	{
		//printf("ST: %d IND: %d\n", stack->value, stack->ind);
		if (stack->next != NULL)
			stack->next->past = stack;
		stack = stack->next;
	}
}