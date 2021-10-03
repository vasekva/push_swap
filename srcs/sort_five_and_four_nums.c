#include "push_swap.h"


/*
 * если флаг == 0 - массив не отсортирован
 * если флаг == 1 - массив отсортирован
 */
int		find_put_ind(t_stack *stack, int required_number, int flag)
{
	//t_stack *tmp;

	//tmp = stack;
	while (stack)
	{
		if (stack->value > required_number)
		{
			if (flag == 0)
			{
				if (!stack->next)
					return (stack->ind);
				if (stack->next->value < required_number)
					return (stack->ind);
			}
			else
			{
				if (stack->ind != 0)
					if (stack->past->value < required_number)
						return (stack->ind);
			}
		}
		// проверка последнего числа
		if (stack->next == NULL)
		{
			if (stack->value < required_number)
				return (stack->ind);
		}
		stack = stack->next;
	}
	return (0);
}

static void	find_range_numbers(t_stack **stack_a, t_stack **stack_b)
{
	//printf("Range #%d: %d - %d;\n", i, minRangeValue, maxRangeValue);
	int		flag;
	t_stack *nth;


	flag = 0;
	nth = NULL;
	while (*stack_b)
	{
		/*
		printf("A: ");
		printLinkedList(*stack_a);
		printf("B: ");
		printLinkedList(*stack_b);
		//*/
		int ind = find_put_ind(*stack_a, (*stack_b)->value, 1);
		if ((*stack_b)->next)
		// если в б несколько элементов
		{
			if ((*stack_b)->value > (*stack_b)->next->value) // если первое больше второго
			{
				nth = get_nth(*stack_a, ind);
				if (nth->past)
					if (nth->past->value < (*stack_b)->next->value)
						flag = 1;
			}
		}
		/*
		printf("VAL: %d\n", get_nth(*stack_a, ind)->value);
		printf("IND: %d\n", ind);
		printf("FLAG: %d\n", flag);
		 */
		if (ind == -1 || ind == 0)
		{
			if (ind == -1)
			{
				if (getLast(*stack_a)->value < (*stack_b)->value)
				{
					push(stack_b, stack_a, "a", 1);
					rotate(stack_a, "a", ft_abs(ind));
					flag = 0;
				}
				else
				{
					reverse_rotate(stack_a, "a", 1);
					if (flag == 1) // если нужно переместить сразу два числа из b в a
					{
						push(stack_b, stack_a, "a", 2);
						rotate(stack_a, "a", 3);
						flag = 0;
					}
					else
					{
						push(stack_b, stack_a, "a", 1);
						rotate(stack_a, "a", 2);
					}
				}
			}
			else
				push(stack_b, stack_a, "a", 1);
			continue;
		}
		if (ind > 0)
			rotate(stack_a, "a", ft_abs(ind));
		else
			reverse_rotate(stack_a, "a", ft_abs(ind));
		push(stack_b, stack_a, "a", 1);
		if (ind > 0)
			reverse_rotate(stack_a, "a", ft_abs(ind));
		else
			rotate(stack_a, "a", ft_abs(ind) + 1);
	}
}

void	sort_five_and_four_nums(t_stack **a, t_stack **b)
{
	if (listLength(*a) == 4)
	{
		push(a, b, "b", 1);
		little_sort(a);
		find_range_numbers(a, b);
	}
	else
	{
		push(a, b, "b", 2);
		little_sort(a);
		find_range_numbers(a, b);
	}
}