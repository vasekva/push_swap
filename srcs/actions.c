#include "push_swap.h"

void	push(t_stack **src, t_stack **dst)
{
	t_stack *tmp;

	if (!(*src) || !(*dst))
		exception(EMPTYSTACK);
	if (!(*src)->next)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dst;
	*dst = (*src);
	*src = tmp;
}

void	swap(t_stack **stack)
{
	t_stack *tmp;

	if (!(*stack))
		exception(EMPTYSTACK);
	if (!(*stack)->next || !(*stack)->next->next)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = (*stack);
	(*stack) = tmp;
}

void	rotate(t_stack **stack)
{
	t_stack *tmp;

	if (!(*stack))
		exception(EMPTYSTACK);
	if (!(*stack)->next)
		return ;
	tmp = (*stack);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (*stack);
	(*stack) = (*stack)->next;
	tmp->next->next = NULL;
}

void reverse_rotate(t_stack **stack)
{
	t_stack *pre_last;
	t_stack *last;

	if (!(*stack))
		exception(EMPTYSTACK);
	if (!(*stack)->next)
		return ;
	pre_last = (*stack);
	while (pre_last->next->next)
		pre_last = pre_last->next;
	last = pre_last->next;
	pre_last->next = NULL;
	last->next = (*stack);
	(*stack) = last;
}