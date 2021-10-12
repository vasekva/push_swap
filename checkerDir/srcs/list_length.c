/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 21:40:48 by jberegon          #+#    #+#             */
/*   Updated: 2021/10/07 21:40:49 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Функция возвращает
 * длину полученного списка.
 */
int	list_length(const t_stack *stack)
{
	int	length;

	length = 0;
	while (stack)
	{
		stack = stack->next;
		length++;
	}
	return (length);
}
