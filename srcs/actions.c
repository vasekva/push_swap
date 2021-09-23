#include "push_swap.h"

void    execute_two_cmds(char *cmd, t_stack **a, t_stack **b)
{
    if (!ft_strncmp("ss", cmd, ft_strlen(cmd)))
    {
        printf("%s\n", "ss");
        swap(a, NULL);
        swap(b, NULL);
    }
    else if (!ft_strncmp("rr", cmd, ft_strlen(cmd)))
    {
        printf("%s\n", "rr");
        rotate(a, NULL);
        rotate(b, NULL);
    }
    else if (!ft_strncmp("rrr", cmd, ft_strlen(cmd)))
    {
        printf("%s\n", "rrr");
        reverse_rotate(a, NULL);
        reverse_rotate(b, NULL);
    }
}

void	push(t_stack **src, t_stack **dst, char *name)
{
	t_stack *tmp;

	if (!(*src))
		return ;
	tmp = (*src)->next;
	(*src)->next = *dst;
	*dst = (*src);
	*src = tmp;
	if (name)
    {
	    printf("%s\n", ft_strjoin("p", name));
    }
}

void	swap(t_stack **stack, char *name)
{
	t_stack *tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = (*stack);
	(*stack) = tmp;
    if (name)
    {
        printf("%s\n", ft_strjoin("s", name));
    }
}

void	rotate(t_stack **stack, char *name)
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
    if (name)
    {
        printf("%s\n", ft_strjoin("r", name));
    }
}

void reverse_rotate(t_stack **stack, char *name)
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
    if (name)
    {
        printf("%s\n", ft_strjoin("rr", name));
    }
}