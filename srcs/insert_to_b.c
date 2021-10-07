/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 01:18:43 by jberegon          #+#    #+#             */
/*   Updated: 2021/10/08 01:18:44 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Функция производит поиск числа сверху списка, диапазон
 * значений которого задан переменными от min_val до max_val.
 *
 * @param stack:	Стэк в котором происходит поиск.
 * @param min_val:	минимальное значения диапазона.
 * @param max_val:	максимальное значение диапазона.
 *
 * @return	Возвращает индекс искомого числа, найденного
 * при проходке сверху списка.\n
 * Если индекс заходит на вторую половину списка - поиск прекращается
 */
static int	find_first_val_front(t_stack *stack, int min_val, int max_val)
{
	while (stack && stack->ind >= 0)
	{
		if (stack->value >= min_val && stack->value <= max_val)
			return (stack->ind);
		stack = stack->next;
	}
	return (0);
}

/**
 * Функция производит поиск числа снизу списка, диапазон
 * значений которого задан переменными от min_val до max_val
 * Если функция доходит до индекса, заданного переменной
 * frontInd или до первой половины стека - поиск прекращается.
 *
 * @param stack :	Стэк в котором происходит поиск.
 * @param min_val :	минимальное значения диапазона.
 * @param max_val : максимальное значение диапазона.
 *
 * @return	Возвращает индекс искомого числа, найденного
 * при проходке снизу списка.
 */
static int	find_first_val_back(t_stack *stack, int frontInd,
							   int min_val, int max_val)
{
	while (stack && stack->ind != frontInd && stack->ind < 0)
	{
		if (stack->value >= min_val && stack->value <= max_val)
			return (stack->ind);
		stack = stack->past;
	}
	return (0);
}

static int	scroll_and_push(t_stack **stack_a, t_stack **stack_b,
							  int rotate_count_b)
{
	int	rotate_count_a;
	int	front_ind;
	int	back_ind;

	front_ind = (*stack_a)->val_ind_front;
	back_ind = (*stack_a)->val_ind_back;
	if ((front_ind <= ft_abs(back_ind) && front_ind >= 0) || back_ind == 0)
		rotate_count_a = front_ind * (-1);
	else
		rotate_count_a = back_ind;
	if ((*stack_a)->cycle_index <= 3 && list_length(*stack_b) <= 3)
	{
		scroll_to_past(stack_a, "a", rotate_count_a);
		push(stack_a, stack_b, "b", 1);
		if (list_length(*stack_b) == 3)
			little_sort_reverse(stack_b);
	}
	else
		rotate_count_b = push_from_a_to_b(stack_a, stack_b,
				rotate_count_a, rotate_count_b);
	return (rotate_count_b);
}

void	insert_to_b(t_stack **stack_a, t_stack **stack_b,
						   int min_range_val, int max_range_val)
{
	int	i;
	int	range_size;
	int	front_ind;
	int	back_ind;
	int	rotate_count_b;

	i = 0;
	rotate_count_b = 0;
	range_size = (*stack_a)->range_size;
	while (i++ < range_size && *stack_a)
	{
		front_ind = find_first_val_front(*stack_a,
				min_range_val, max_range_val);
		back_ind = find_first_val_back(*stack_a, front_ind,
				min_range_val, max_range_val);
		if (front_ind == 0 && back_ind == 0
			&& ((*stack_a)->value < min_range_val
				|| (*stack_a)->value > max_range_val))
			continue ;
		(*stack_a)->val_ind_front = front_ind;
		(*stack_a)->val_ind_back = back_ind;
		(*stack_a)->cycle_index = i;
		rotate_count_b = scroll_and_push(stack_a, stack_b, rotate_count_b);
	}
	scroll_to_past(stack_b, "b", rotate_count_b);
}
