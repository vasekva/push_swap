#include "push_swap.h"

int	push_from_a_to_b(t_stack **stack_a, t_stack **stack_b, int rotate_count_a, int rotate_count_b)
{
	t_stack *tmp;
	int	flag;

	flag = 0;
	tmp = *stack_b;
	/*
	printf("B: ");
	printLinkedList(*stack_b);
	printf("==========PUSH_STACK_B==========\n");
	printf("PUSH value %d\n", (*stack_a)->value);
*/
	while (tmp->next)
	{
		if (getLast(tmp)->value > (*stack_a)->value)
		{
			break;
		}
		tmp = tmp->next;
	}
	if (listLength(*stack_b) >= 2)
	{
		if ((*stack_a)->value > (*stack_b)->value)
		{
			if ((*stack_a)->value < getLast(*stack_b)->value)
				flag = 1;
		}
	}
	if (flag != 0)
	{
		scroll_to_past(stack_a, "a", rotate_count_a);
		//printf("Возможное дополнение чисел!\n");
		push(stack_a, stack_b, "b", 1);
		if (rotate_count_b != 0)
		{
			if (rotate_count_b < 0)
				--rotate_count_b;
		}
	}
	else
	{
		/*
		printf("Дополнения чисел нет!\n");
		printf("Откручиваем значения: \n");
		printLinkedList(*stack_b);
		 */
		// Возвращение чисел в стеке на прежние места, если взятое число встает "не в свое место"
		//if (rotate_count != 0)
		scroll_to_past(stack_b, "b", rotate_count_b);

		//scroll_stacks(stack_a, stack_b, rotate_count_a, rotate_count_b);

/*
		if (rotate_count != 0)
		{
			if (rotate_count < 0)
				rotate(stack_b, "b", ft_abs(rotate_count));
			else
				reverse_rotate(stack_b, "b", ft_abs(rotate_count));
		}
*/
		//printf("Результат для push_stack_b: \n");
		//printLinkedList(*stack_b);
		rotate_count_b = push_stack_b(stack_a, stack_b, rotate_count_a, rotate_count_b);
	}
	return (rotate_count_b);
}