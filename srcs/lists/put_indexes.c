/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_indexes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 00:39:25 by jberegon          #+#    #+#             */
/*   Updated: 2021/10/13 00:39:27 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_indexes(t_stack *stack)
{
	int	mid_pos;
	int	len;
	int	ind;
	int	i;

	i = 0;
	ind = 0;
	len = list_length(stack);
	mid_pos = (len / 2);
	if (len % 2 != 0)
		++mid_pos;
	while (stack)
	{
		if (i < mid_pos)
			stack->ind = (ind++);
		else
		{
			if (!(len % 2 == 0 && i == mid_pos))
				ind--;
			stack->ind = (ind) * -1;
		}
		i++;
		stack = stack->next;
	}
}
