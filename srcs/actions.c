#include "push_swap.h"

void    execute_two_cmds(char *cmd, t_stack **a, t_stack **b, int count)
{
	while (count--)
	{
		if (!ft_strncmp("ss", cmd, ft_strlen(cmd)))
		{
			swap(a, NULL, 1);
			swap(b, NULL, 1);
			print_action_message(NULL, "ss");
		}
		else if (!ft_strncmp("rr", cmd, ft_strlen(cmd)))
		{
			rotate(a, NULL, 1);
			rotate(b, NULL, 1);
			print_action_message(NULL, "rr");
		}
		else if (!ft_strncmp("rrr", cmd, ft_strlen(cmd)))
		{
			reverse_rotate(a, NULL, 1);
			reverse_rotate(b, NULL, 1);
			print_action_message(NULL, "rrr");
		}
	}
}

void	push(t_stack **src, t_stack **dst, char *name, int count)
{
	t_stack *tmp;

	while (count--)
	{
		if (!(*src))
			return ;
		tmp = (*src)->next;
		(*src)->next = *dst;
		*dst = (*src);
		*src = tmp;
		put_indexes(*src);
		put_indexes(*dst);
		print_action_message(name, "p");
	}
}

void	swap(t_stack **stack, char *name, int count)
{
	t_stack *tmp;

	while (count--)
	{
		if (!(*stack) || !(*stack)->next)
			return;
		tmp = (*stack)->next;
		(*stack)->next = tmp->next;
		tmp->next = (*stack);
		(*stack) = tmp;
		put_indexes(*stack);
		print_action_message(name, "s");
	}
}

void	rotate(t_stack **stack, char *name, int count)
{
	t_stack *tmp;

	while (count--)
	{
		if (!(*stack) || !(*stack)->next)
			return;
		tmp = (*stack);
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (*stack);
		(*stack) = (*stack)->next;
		tmp->next->next = NULL;
		put_indexes(*stack);
		print_action_message(name, "r");
	}
}

void reverse_rotate(t_stack **stack, char *name, int count)
{
	t_stack *pre_last;
	t_stack *last;

	while (count--)
	{
		if (!(*stack) || !(*stack)->next)
			return;
		pre_last = (*stack);
		while (pre_last->next->next)
			pre_last = pre_last->next;
		last = pre_last->next;
		pre_last->next = NULL;
		last->next = (*stack);
		(*stack) = last;
		put_indexes(*stack);
		print_action_message(name, "rr");
	}
}