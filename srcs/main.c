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

static void	start_program(int argc, char **argv)
{
	int		length;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	while (argc--)
	{
		if (ft_strlen(argv[argc]) == 0)
			exception("Error");
	}
	parse_parameters(argv);
	fill_list(argv, &stack_a);
	length = list_length(stack_a);
	put_indexes(stack_a);
	checkLinkedList(stack_a);
	if (is_sorted(stack_a) == 1)
		return ;
	if (length <= 3)
		little_sort(&stack_a);
	else if (length <= 5)
		sort_five_and_four_nums(&stack_a, &stack_b);
	else
		big_sort(&stack_a, &stack_b);
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
	{
		start_program(argc, argv);
	}
	else
		exception(FEWPARAMS);
	return (0);
}

//TODO: после написания программы проверить, используется ли флаг
// 1 в функции find_put_ind();
//TODO: удалить printLinkedList и удалить библиотеку для printf
//TODO: посмотреть работу strjoin с неаллоцированными строками
// (нужно ли free(tmp))
/*
printf("REZ: \n");
printf("A:\n");
printLinkedList(stack_a);
printf("B:\n");
printLinkedList(stack_b);
//*/

/*
 * make re; ./push_swap $ARG | ./checker_Mac $ARG; ./push_swap $ARG | wc -l;
 * ./push_swap $ARG | ./checker $ARG
 */
