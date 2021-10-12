/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 01:18:20 by jberegon          #+#    #+#             */
/*   Updated: 2021/10/08 01:18:21 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (-1);
		stack = stack->next;
	}
	return (1);
}

static void	start_program(int argc, char **argv,
							 t_stack **stack_a, t_stack **stack_b)
{
	int		length;

	while (argc--)
	{
		if (ft_strlen(argv[argc]) == 0)
			exception("Error");
	}
	parse_parameters(argv);
	fill_list(argv, stack_a);
	length = list_length(*stack_a);
	if (length >= 550)
		exception(TOOMANY);
	put_indexes(*stack_a);
	checkLinkedList(*stack_a);
	if (is_sorted(*stack_a) == 1)
		return ;
	if (length <= 3)
		little_sort(stack_a);
	else if (length <= 5)
		sort_five_and_four_nums(stack_a, stack_b);
	else
		big_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc >= 2)
	{
		start_program(argc, argv, &stack_a, &stack_b);
		stack_a = get_last(stack_a);
		while (stack_a->past)
		{
			stack_a = stack_a->past;
			free(stack_a->next);
		}
		free(stack_a);
	}
	else
		exception(FEWPARAMS);
	return (0);
}

/*
 * make re; ./push_swap $ARG | ./checker_Mac $ARG; ./push_swap $ARG | wc -l;
 * ./push_swap $ARG | ./checker $ARG
 */
