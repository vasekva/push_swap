#include "push_swap.h"

void    execute_two_cmds(char *cmd, t_stack **a, t_stack **b)
{
    if (!ft_strncmp("ss", cmd, ft_strlen(cmd)))
    {
        printf("%s\n", "swapA && swapB");
        swap(a);
        swap(b);
    }
    else if (!ft_strncmp("rr", cmd, ft_strlen(cmd)))
    {
        printf("%s\n", "rotateA && rotateB");
        rotate(a);
        rotate(b);
    }
    else if (!ft_strncmp("rrr", cmd, ft_strlen(cmd)))
    {
        printf("%s\n", "reverse_rotateA && reverse_rotateB");
        reverse_rotate(a);
        reverse_rotate(b);
    }
}

void	push(t_stack **src, t_stack **dst)
{
	t_stack *tmp;

	if (!(*src))
		return ;
	tmp = (*src)->next;
	(*src)->next = *dst;
	*dst = (*src);
	*src = tmp;
}

void	swap(t_stack **stack)
{
	t_stack *tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = (*stack);
	(*stack) = tmp;
}

void	rotate(t_stack **stack)
{
	t_stack *tmp;

	if (!(*stack) || !(*stack)->next)
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

	if (!(*stack) || !(*stack)->next)
		return ;
	pre_last = (*stack);
	while (pre_last->next->next)
		pre_last = pre_last->next;
	last = pre_last->next;
	pre_last->next = NULL;
	last->next = (*stack);
	(*stack) = last;
}