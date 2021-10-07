/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort_reverse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 01:18:30 by jberegon          #+#    #+#             */
/*   Updated: 2021/10/08 01:18:31 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_ind_min(t_stack *stack)
{
	int		ind_min;
	int		min_val;
	t_stack	*tmp;

	ind_min = 0;
	min_val = stack->value;
	tmp = stack;
	while (tmp)
	{
		if (tmp->value < min_val)
		{
			min_val = tmp->value;
			ind_min = tmp->ind;
		}
		tmp = tmp->next;
	}
	return (ind_min);
}

static int	find_ind_max(t_stack *stack)
{
	int		ind_max;
	int		max_val;
	t_stack	*tmp;

	ind_max = 0;
	max_val = stack->value;
	tmp = stack;
	while (tmp)
	{
		if (tmp->value > max_val)
		{
			max_val = tmp->value;
			ind_max = tmp->ind;
		}
		tmp = tmp->next;
	}
	return (ind_max);
}

static void	sort_three_values(int ind_min, int ind_max,
							  t_stack **stack, char *stack_name)
{
	if (ind_min == 0)
	{
		if (ind_max == 1)
			rotate(stack, stack_name, 1);
		else
		{
			rotate(stack, stack_name, 1);
			swap(stack, stack_name, 1);
		}
	}
	else if (ind_max != 0)
	{
		if (ind_min == 1)
			reverse_rotate(stack, stack_name, 1);
		else
			swap(stack, stack_name, 1);
	}
	else
	{
		if (ind_min == 1)
		{
			swap(stack, stack_name, 1);
			rotate(stack, stack_name, 1);
		}
	}
}

void	little_sort_reverse(t_stack **stack)
{
	int	ind_min;
	int	ind_max;

	ind_max = find_ind_max(*stack);
	ind_min = find_ind_min(*stack);
	if (list_length(*stack) == 2 && ind_max == 1)
	{
		swap(stack, "b", 1);
		return ;
	}
	else
		sort_three_values(ind_min, ind_max, stack, "b");
}
