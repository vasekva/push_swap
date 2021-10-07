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

/*
void do_actions(t_stack *a, t_stack *b)
{
	char *action;

	action = NULL;
	while (1)
	{
		get_next_line(0, &action);
		if (!ft_strncmp("pa", action, ft_strlen(action)))
		{
			printf("%s\n", "pushA");
			push(&b, &a, "a", 1);
		}
		else if (!ft_strncmp("pb", action, ft_strlen(action)))
		{
			printf("%s\n", "pushB");
			push(&a, &b, "b", 1);
		}
        else if (!ft_strncmp("sa", action, ft_strlen(action)))
		{
			printf("%s\n", "swapA");
			swap(&a, "a", 1);
		}
        else if (!ft_strncmp("sb", action, ft_strlen(action)))
		{
			printf("%s\n", "swapB");
			swap(&b, "b", 1);
		}
        else if (!ft_strncmp("ra", action, ft_strlen(action)))
		{
			printf("%s\n", "rotateA");
			rotate(&a, "a", 1);
		}
        else if (!ft_strncmp("rb", action, ft_strlen(action)))
		{
			printf("%s\n", "rotateB");
			rotate(&b, "b", 1);
		}
        else if (!ft_strncmp("rra", action, ft_strlen(action)))
		{
			printf("%s\n", "reverse_rotateA");
			reverse_rotate(&a, "a", 1);
		}
        else if (!ft_strncmp("rrb", action, ft_strlen(action)))
		{
			printf("%s\n", "reverse_rotateB");
			reverse_rotate(&b, "b", 1);
		}
        else
            execute_two_cmds(action, &a, &b, 1);
		free(action);
		printf("A: ");
		printLinkedList(a);
		printf("B: ");
		printLinkedList(b);
	}
}
*/
void	put_indexes(t_stack *stack)
{
	int	mid_pos;
	int	len;
	int	ind;
	int	i;

	i = 0;
	ind = 0;
	len = list_length(stack);
	mid_pos = (len / 2);
	if (len % 2 != 0)
		++mid_pos;
	while (stack)
	{
		if (i < mid_pos)
			stack->ind = (ind++);
		else
		{
			if (!(len % 2 == 0 && i == mid_pos))
				ind--;
			stack->ind = (ind) * -1;
		}
		i++;
		stack = stack->next;
	}
}

int	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (-1);
		stack = stack->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		length;

	stack_a = NULL;
	stack_b = NULL;
	if (argc >= 2)
	{
		parse_parameters(argv);
		fill_list(argv, &stack_a);
		if (is_sorted(stack_a) == 1)
			return (0);
		length = list_length(stack_a);
		put_indexes(stack_a);
		checkLinkedList(stack_a);
		if (length <= 3)
			little_sort(&stack_a);
		else if (length <= 5)
			sort_five_and_four_nums(&stack_a, &stack_b);
		else
			big_sort(&stack_a, &stack_b);
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
