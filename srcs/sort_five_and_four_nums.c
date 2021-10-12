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
				if (stack->ind != 0 && (stack->past->value < required_number))
					return (stack->ind);
			}
		}
		if (flag == 1 && (stack->next == NULL
				&& stack->value < required_number))
			return (stack->ind);
		stack = stack->next;
	}
	return (0);
}

static int	get_ind(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (stack->ind);
		stack = stack->next;
	}
	return (0);
}

static void	push_min(t_stack **a, t_stack **b)
{
	int	min;
	int	ind;

	min = find_min_value(*a);
	ind = get_ind(*a, min);
	if (ind > 0)
		rotate(a, "a", ind);
	if (ind < 0)
	{
		reverse_rotate(a, "a", ft_abs(ind));
	}
	push(a, b, "b", 1);
}

void	sort_five_and_four_nums(t_stack **a, t_stack **b)
{
	if (list_length(*a) == 4)
	{
		push_min(a, b);
		little_sort(a);
		push(b, a, "a", 1);
	}
	else
	{
		push_min(a, b);
		push_min(a, b);
		little_sort(a);
		push(b, a, "a", 2);
	}
}
