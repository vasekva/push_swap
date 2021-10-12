/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 21:40:57 by jberegon          #+#    #+#             */
/*   Updated: 2021/10/07 21:40:58 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Функция создает новый элемент с
 * переданным в параметры значением и
 * вставляет его в конец списка.
 * В новом элементе сохраняется указатель
 * на предыдущее значение и устанавливается
 * NULL для следующего.
 *
 * @param stack: Список, в который
 * производится вставка.
 *
 * @param value: Значение для вставки
 * в созданный элемент.
 */
void	push_back(t_stack **stack, int value)
{
	t_stack	*last;
	t_stack	*tmp;

	last = get_last(*stack);
	if (!last)
	{
		(*stack) = (t_stack *)malloc(sizeof(t_stack));
		(*stack)->value = value;
		(*stack)->next = NULL;
		(*stack)->past = NULL;
	}
	else
	{
		tmp = (t_stack *)malloc(sizeof(t_stack));
		tmp->value = value;
		tmp->next = NULL;
		tmp->past = last;
		last->next = tmp;
	}
}
