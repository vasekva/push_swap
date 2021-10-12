/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_past_pointers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 21:41:05 by jberegon          #+#    #+#             */
/*   Updated: 2021/10/07 21:41:06 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_past_pointers(t_stack *stack)
{
	if (!stack)
		return ;
	stack->past = NULL;
	while (stack->next)
	{
		if (stack->next != NULL)
			stack->next->past = stack;
		stack = stack->next;
	}
}
