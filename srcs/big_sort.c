/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 01:19:46 by jberegon          #+#    #+#             */
/*   Updated: 2021/10/08 01:19:47 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	main_sort_cycle(t_stack **stack_a, t_stack **stack_b,
							   int size_of_range, int i)
{
	int	minRangeValue;
	int	maxRangeValue;
	int	max;
	int	min;

	max = find_max_value(*stack_a);
	min = find_min_value(*stack_a);
	while (*stack_a)
	{
		(*stack_a)->range_size = size_of_range;
		if (list_length(*stack_a) <= 10)
		{
			minRangeValue = min;
			maxRangeValue = max;
		}
		else
		{
			minRangeValue = min + size_of_range * (i - 1);
			maxRangeValue = minRangeValue + size_of_range - 1;
		}
		insert_to_b(stack_a, stack_b, minRangeValue, maxRangeValue);
		i++;
	}
	while (*stack_b)
		push(stack_b, stack_a, "a", 1);
}

static int	def_range_size(int len, int num_of_values, t_stack **stack_a)
{
	int	range_size;
	int	number_of_ranges;
	int	min;
	int	max;

	min = find_min_value(*stack_a);
	max = find_max_value(*stack_a);
	if (len <= 10)
	{
		range_size = len;
		number_of_ranges = 1;
	}
	else
	{
		number_of_ranges = len / num_of_values;
		if (len % num_of_values != 0)
			number_of_ranges++;
		range_size = (max - min + 1) / number_of_ranges;
		range_size += 7;
	}
	return (range_size);
}

void	big_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	num_of_values;
	int	range_size;
	int	len;

	if (list_length(*stack_a) <= 100 && list_length(*stack_a) > 20)
		num_of_values = 9;
	else
		num_of_values = 20;
	len = list_length(*stack_a);
	range_size = def_range_size(len, num_of_values, stack_a);
	main_sort_cycle(stack_a, stack_b, range_size, 1);
}
