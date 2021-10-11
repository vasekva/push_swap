/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 01:17:34 by jberegon          #+#    #+#             */
/*   Updated: 2021/10/08 01:17:36 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Функция возвращает модуль
 * полученного числа.
 */
int	ft_abs(int number)
{
	if (number < 0)
		return (-number);
	else
		return (number);
}

void	arr_free(char **array)
{
	int	ind;

	ind = 0;
	if (array != NULL)
	{
		while (array[ind])
		{
			if (array[ind] != NULL)
			{
				free(array[ind]);
				array[ind] = NULL;
			}
			ind++;
		}
		free(array);
		array = NULL;
	}
}

int	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}