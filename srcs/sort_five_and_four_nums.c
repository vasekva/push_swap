#include "push_swap.h"

int		find_put_ind(t_stack *a, int required_number)
{
	t_stack *tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->value < required_number
			&& tmp->next->value > required_number)
			return (tmp->ind);
		tmp = tmp->next;
	}
	return (0);
}

void	cycle_rotate_stack(t_stack **a, t_stack **b, int req_index)
{
	int mid_pos;
	int count;
	int	i;

	i = 0;
	mid_pos = listLength(*a) / 2;
	if (listLength(*a) % 2 != 0)
		++mid_pos;
	if (req_index < 0 || req_index == mid_pos) // если позиция для вставки в правой половине
	{
		count = ft_abs(--req_index) + 1;
		while (++i < count)
		{
			reverse_rotate(a, "a");
		}
		push(b, a, "a");
		while (count--)
			rotate(a, "a");
	}
	else // если в левой половине
	{
		count = ft_abs(req_index) + 1;
		while (++i < count)
		{
			rotate(a, "a");
		}
		push(b, a, "a");
		while (--count)
			reverse_rotate(a, "a");
	}
}

void	put_value_to_list(t_stack **a, t_stack **b)
{
	t_stack *tmp;

	tmp = (*a);
	if ((*b)->value < (*a)->value)
		push(b, a, "a");
	else if ((*b)->value > getLast(tmp)->value)
	{
		push(b, a, "a");
		rotate(a, "a");
	}
	else
	{
		//printLinkedList(*a, listLength(*a));
		cycle_rotate_stack(a, b, find_put_ind(*a, (*b)->value));
	}
}

void	sort_five_and_four_nums(t_stack **a, t_stack **b)
{
	if (listLength(*a) == 4)
	{
		push(a, b, "b");
		little_sort(a);
		put_value_to_list(a, b);
	}
	/*else
	{
		push(a, b, "b");
		push(a, b, "b");
		little_sort(a);
		put_value_to_list(a, b);
	}*/
}