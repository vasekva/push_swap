/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 01:19:37 by jberegon          #+#    #+#             */
/*   Updated: 2021/10/08 01:19:38 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (!(*src))
		return ;
	tmp = (*src)->next;
	(*src)->next = *dst;
	*dst = (*src);
	*src = tmp;
	put_past_pointers(*src);
	put_past_pointers(*dst);
}

void	swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = (*stack);
	(*stack) = tmp;
	put_past_pointers(*stack);
}

void	rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = (*stack);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (*stack);
	(*stack) = (*stack)->next;
	tmp->next->next = NULL;
	put_past_pointers(*stack);
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*pre_last;
	t_stack	*last;

	if (!(*stack) || !(*stack)->next)
		return ;
	pre_last = (*stack);
	while (pre_last->next->next)
		pre_last = pre_last->next;
	last = pre_last->next;
	pre_last->next = NULL;
	last->next = (*stack);
	(*stack) = last;
	put_past_pointers(*stack);
}
