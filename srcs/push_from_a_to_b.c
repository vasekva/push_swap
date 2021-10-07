/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_from_a_to_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 01:18:05 by jberegon          #+#    #+#             */
/*   Updated: 2021/10/08 01:18:06 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_without_scroll_b(t_stack **stack_a, t_stack **stack_b,
				  int rotate_count_a, int rotate_count_b)
{
	scroll_to_past(stack_a, "a", rotate_count_a);
	push(stack_a, stack_b, "b", 1);
	if (rotate_count_b != 0)
	{
		if (rotate_count_b < 0)
			--rotate_count_b;
	}
	return (rotate_count_b);
}

static int	is_possible_addition(t_stack **stack_a, t_stack **stack_b)
{
	if (list_length(*stack_b) >= 2)
	{
		if ((*stack_a)->value > (*stack_b)->value)
		{
			if ((*stack_a)->value < get_last(*stack_b)->value)
				return (1);
		}
	}
	return (0);
}

int	push_from_a_to_b(t_stack **stack_a, t_stack **stack_b,
					 int rotate_count_a, int rotate_count_b)
{
	t_stack	*tmp;
	int		flag;

	tmp = *stack_b;
	while (tmp->next)
	{
		if (get_last(tmp)->value > (*stack_a)->value)
			break ;
		tmp = tmp->next;
	}
	flag = is_possible_addition(stack_a, stack_b);
	if (flag != 0)
	{
		rotate_count_b = push_without_scroll_b(stack_a, stack_b,
				rotate_count_a, rotate_count_b);
	}
	else
	{
		scroll_to_past(stack_b, "b", rotate_count_b);
		rotate_count_b = push_stack_b(stack_a, stack_b,
				rotate_count_a, rotate_count_b);
	}
	return (rotate_count_b);
}
