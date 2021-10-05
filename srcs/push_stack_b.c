#include "push_swap.h"

/*
 * rotate - <- (-1)
 * reverse_rotate - -> (+1)
 */

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

int	push_bigger_value(t_stack **stack_a, t_stack **stack_b, int roll_count, int put_ind)
{
	// если число для пуша больше последнего числа в б, то
	// 1) возвращаем на место число в стеке b
	// 2) cдвигаем числа в нужное положение
	// 3) сохраняем итерации для возврата его на место и пушим
	if ((*stack_a)->value > getLast(*stack_b)->value)
	{
		printf("&& A > Last_B\n");
		// 1)

		if (roll_count > 0)
			rotate(stack_b, "b", ft_abs(roll_count) + 1);
		else if (roll_count < 0)
			reverse_rotate(stack_b, "b", ft_abs(roll_count));
		roll_count = put_ind;
		// 2)
		printf("B: ");
		printLinkedList(*stack_b);
		printf("PUT_IND: %d\n", put_ind);
		//rotate(stack_b, "b",  1);
		//if (put_ind < 0)
		//	reverse_rotate(stack_b, "b", abs(put_ind));
		//else
		//	rotate(stack_b, "b", abs(put_ind));
		// 3)
		push(stack_a, stack_b, "b",1);
	}
	else
	{
		printf("&& A < Last_B\n");
		if (roll_count < 0)
			--roll_count;
		else if (roll_count > 0)
			++roll_count;
		else
			roll_count = put_ind;
		push(stack_a, stack_b, "b", 1);
	}
}

int	push_smaller_value(t_stack **stack_a, t_stack **stack_b, int roll_count, int put_ind)
{
	t_stack *tmp;

	tmp = *stack_b;
	if ((*stack_a)->value > getLast(*stack_b)->value)
	{
		printf("&& A > Last_B\n");
		int flag = 1;
		while (tmp)
		{
			if (tmp->next)
			{
				// если числа пошли на убывание и число больше, чем то, что хотим ставить
				if (tmp->next->value < tmp->value
				&& tmp->next->value > (*stack_a)->value)
				{
					flag = 0;
				}
			}
			tmp = tmp->next;
		}
		if (flag != 0)
		{
			roll_count = put_ind;
			printf("Возможное дополнение чисел!\n");
		}
		else
		{
			if (get_nth(*stack_b, put_ind)->past)
			{
				if (get_nth(*stack_b, put_ind)->ind < 0
				&& get_nth(*stack_b, put_ind)->past->ind > 0)
				{
					if (put_ind < 0)
						++put_ind;
					else if (put_ind > 0)
						--put_ind;
					//if (put_ind < 0)
					//	reverse_rotate(stack_b, "b", ft_abs(put_ind));
					//else if (put_ind > 0)
					//	rotate(stack_b, "b", ft_abs(put_ind));
				}
			}
			if (put_ind < 0)
				reverse_rotate(stack_b, "b", ft_abs(put_ind) + 1);
			else if (put_ind > 0)
				rotate(stack_b, "b", ft_abs(put_ind));
			push(stack_a, stack_b, "b", 1);
			roll_count = put_ind;
			if (put_ind < 0)
				--roll_count;
			else if (put_ind > 0)
				++roll_count;
		}
		printf("roll_count = %d\n", roll_count);
	}
	else
	{
		printf("&& A < Last_B\n");
		int flag = 1;
		while (tmp)
		{
			if (tmp->next)
			{
				// если числа пошли на убывание и число больше, чем то, что хотим ставить
				if (tmp->next->value < tmp->value
				&& tmp->next->value > (*stack_a)->value
				&& tmp->next->value != getLast(tmp)->value)
				{
					flag = 0;
				}
			}
			tmp = tmp->next;
		}
		if (flag != 0)
		{
			roll_count = put_ind;
			printf("Возможное дополнение чисел!\n");
		}
		/*
		if (put_ind == -1)
		{
			push(stack_a, stack_b, "b", 1);
			//rotate(stack_b, "b", 1);
			--roll_count;
		}*/
		else
		{
			//roll_count = put_ind;
			if (roll_count < 0)
				reverse_rotate(stack_b, "b", ft_abs(roll_count));
			else if (roll_count > 0)
				rotate(stack_b, "b", ft_abs(roll_count));
			roll_count = put_ind;
		}
		push(stack_a, stack_b, "b", 1);
	}
}

void	push_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	int put_ind;
	int	number;

	number = (*stack_a)->value;
	put_ind = find_put_ind(*stack_b, number, 0);
	if (!(*stack_b))
	{
		push(stack_a, stack_b, "b", 1);
		return;
	}
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