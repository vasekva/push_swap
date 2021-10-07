/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_and_four_nums.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 01:17:45 by jberegon          #+#    #+#             */
/*   Updated: 2021/10/08 01:17:46 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * если флаг == 0 - массив не отсортирован
 * если флаг == 1 - массив отсортирован
 */
int	find_put_ind(t_stack *stack, int required_number, int flag)
{
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
		if (flag == 1)
		{
			if (stack->next == NULL)
				if (stack->value < required_number)
					return (stack->ind);
		}
		stack = stack->next;
	}
	return (0);
}

static void	push_to_begin_or_end(t_stack **stack_a, t_stack **stack_b,
								 int put_ind, int flag)
{
	if (put_ind == -1)
	{
		if (get_last(*stack_a)->value < (*stack_b)->value)
		{
			push(stack_b, stack_a, "a", 1);
			rotate(stack_a, "a", ft_abs(put_ind));
			flag = 0;
		}
		else
		{
			reverse_rotate(stack_a, "a", 1);
			if (flag == 1)
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
}

static void	find_range_numbers(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*nth;
	int		flag;
	int		ind;

	flag = 0;
	nth = NULL;
	while (*stack_b)
	{
		ind = find_put_ind(*stack_a, (*stack_b)->value, 1);
		if ((*stack_b)->next)
		{
			if ((*stack_b)->value > (*stack_b)->next->value)
			{
				nth = get_nth(*stack_a, ind);
				if (nth->past)
					if (nth->past->value < (*stack_b)->next->value)
						flag = 1;
			}
		}
		if (ind == -1 || ind == 0)
		{
			push_to_begin_or_end(stack_a, stack_b, ind, flag);
			continue ;
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
	if (list_length(*a) == 4)
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
