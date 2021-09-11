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

void	swap(t_stack **swap_stack)
{
	t_stack *tmp;

	if (!(*swap_stack))
		exception(EMPTYSTACK);
	if (!(*swap_stack)->next || !(*swap_stack)->next->next)
		return ;
	tmp = (*swap_stack)->next;
	(*swap_stack)->next = tmp->next;
	tmp->next = (*swap_stack);
	(*swap_stack) = tmp;
}
