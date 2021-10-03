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

void	cycle_rotate_stack(t_stack **a, t_stack **b, int req_index)
{
	int mid_pos;
	int count;
	int	i;

	i = 0;
	mid_pos = listLength(*a) / 2;
	if (listLength(*a) % 2 != 0)
		++mid_pos;
	if (req_index < 0 || req_index == mid_pos) // если позиция для вставки в правой половине
	{
		count = ft_abs(--req_index) + 1;
		while (++i < count)
		{
			reverse_rotate(a, "a", 1);
		}
		push(b, a, "a", 1);
		while (count--)
			rotate(a, "a", 1);
	}
	else // если в левой половине
	{
		count = ft_abs(req_index) + 1;
		while (++i < count)
		{
			rotate(a, "a", 1);
		}
		push(b, a, "a", 1);
		while (--count)
			reverse_rotate(a, "a", 1);
	}
}

void	put_value_to_list(t_stack **a, t_stack **b)
{
	t_stack *tmp;

	tmp = (*a);
	if ((*b)->value < (*a)->value)
		push(b, a, "a", 1);
	else if ((*b)->value > getLast(tmp)->value)
	{
		push(b, a, "a", 1);
		rotate(a, "a", 1);
	}
	else
	{
		//printLinkedList(*a, listLength(*a));
		cycle_rotate_stack(a, b, find_put_ind(*a, (*b)->value, 0));
	}
}

static void	find_range_numbers(t_stack **stack_a, t_stack **stack_b)
{
	//printf("Range #%d: %d - %d;\n", i, minRangeValue, maxRangeValue);




	while (*stack_b)
	{
		/*
		printf("A: ");
		printLinkedList(*stack_a);
		printf("B: ");
		printLinkedList(*stack_b);
		//*/
		int ind = find_put_ind(*stack_a, (*stack_b)->value, 1);
		//printf("IND: %d\n", ind);
		if (ind == -1 || ind == 0)
		{
			if (ind == -1)
			{
				if (getLast(*stack_a)->value < (*stack_b)->value)
				{
					push(stack_b, stack_a, "a", 1);
					rotate(stack_a, "a", ft_abs(ind));
				}
				else
				{
					reverse_rotate(stack_a, "a", 1);
					push(stack_b, stack_a, "a", 1);
					rotate(stack_a, "a", 2);
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
		//put_value_to_list(a, b);
	}
	else
	{
		push(a, b, "b", 2);
		little_sort(a);
		find_range_numbers(a, b);
		//put_value_to_list(a, b);
	}
}