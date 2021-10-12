/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_put_ind.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 00:44:04 by jberegon          #+#    #+#             */
/*   Updated: 2021/10/13 00:44:05 by jberegon         ###   ########.fr       */
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
