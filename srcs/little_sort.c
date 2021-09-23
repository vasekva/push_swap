#include "push_swap.h"

static int find_ind_min(t_stack *stack)
{
    int		ind_min;
	int		min_val;
    t_stack	*tmp;

	ind_min = 1;
	min_val = stack->value;
	tmp = stack;
    while (tmp)
    {
        if (tmp->value < min_val)
        {
            min_val = tmp->value;
            ind_min = tmp->ind;
        }
        tmp = tmp->next;
    }
	return (ind_min);
}

static int	find_ind_max(t_stack *stack)
{
	int		ind_max;
	int		max_val;
	t_stack	*tmp;

	ind_max = 1;
	max_val = stack->value;
	tmp = stack;
	while (tmp)
	{
		if (tmp->value > max_val)
		{
			max_val = tmp->value;
			ind_max = tmp->ind;
		}
		tmp = tmp->next;
	}
	return (ind_max);
}

void	sort_three_values(int ind_min, int ind_max, t_stack **stack, char *stack_name)
{
	if (ind_min == 1 && ind_max == 2) // 132
	{
		swap(stack, stack_name);
		rotate(stack, stack_name);
	}
	else if (ind_min != 1 && ind_max != 1)
	{
		if (ind_min == 2) // 213
			swap(stack, stack_name);
		else // 231
			reverse_rotate(stack, stack_name);
	}
	else if  (ind_max == 1)
	{
		if (ind_min == 2) //312
			rotate(stack, stack_name);
		else
		{
			swap(stack, "a");
			reverse_rotate(stack, stack_name);
		}
	}
}

void	little_sort(t_stack **stack)
{
    int	ind_min;
    int	ind_max;

    ind_max = find_ind_max(*stack);
    ind_min = find_ind_min(*stack);
    if (listLength(*stack) == 2 && ind_max == 1)
    {
		swap(stack, "a");
		return ;
	}
    else
    	sort_three_values(ind_min, ind_max, stack, "a");
}