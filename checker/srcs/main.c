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


void do_actions(t_stack *a, t_stack *b)
{
	char *action;

	action = NULL;
	while (1)
	{
		get_next_line(0, &action);
		if (!ft_strncmp("pa", action, ft_strlen(action)))
			push(&b, &a);
		else if (!ft_strncmp("pb", action, ft_strlen(action)))
			push(&a, &b);
        else if (!ft_strncmp("sa", action, ft_strlen(action)))
			swap(&a);
        else if (!ft_strncmp("sb", action, ft_strlen(action)))
		{
			swap(&b);
		}
        else if (!ft_strncmp("ra", action, ft_strlen(action)))
		{
			rotate(&a);
		}
        else if (!ft_strncmp("rb", action, ft_strlen(action)))
		{
			rotate(&b);
		}
        else if (!ft_strncmp("rra", action, ft_strlen(action)))
		{
			reverse_rotate(&a);
		}
        else if (!ft_strncmp("rrb", action, ft_strlen(action)))
		{
			reverse_rotate(&b);
		}
		else if (!ft_strncmp(" ", " ", 1))
		{
			if (is_sorted(a))
				write(1, "OK\n", 3);
			else
				write(1, "KO\n", 3);
			free(action);
			return ;
		}
        else
            execute_two_cmds(action, &a, &b);
		free(action);
		printf("A: ");
		printLinkedList(a);
		printf("B: ");
		printLinkedList(b);
	}
}

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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc >= 2)
	{
		parse_parameters(argv);
		fill_list(argv, &stack_a);
		put_indexes(stack_a);
		checkLinkedList(stack_a);
		printLinkedList(stack_a);
		do_actions(stack_a, stack_b);
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
