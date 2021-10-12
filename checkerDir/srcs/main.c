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

int	check_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b)
	{
		write(1, "KO\n", 3);
		return (0);
	}
	if (is_sorted(stack_a))
	{
		write(1, "OK\n", 3);
		return (1);
	}
	else
	{
		write(1, "KO\n", 3);
		return (0);
	}
}

void do_actions(t_stack *a, t_stack *b)
{
	char *cmd;

	cmd = NULL;
	int ret = 0;
	while (1)
	{
		ret = get_next_line(0, &cmd);
		if (ret == -333)
		{
			if (check_stacks(a, b))
				exit(0);
			else
				exit(1);
		}
		if (!ft_strncmp("pa", cmd, ft_strlen(cmd)))
			push(&b, &a);
		else if (!ft_strncmp("pb", cmd, ft_strlen(cmd)))
			push(&a, &b);
        else if (!ft_strncmp("sa", cmd, ft_strlen(cmd)))
			swap(&a);
        else if (!ft_strncmp("sb", cmd, ft_strlen(cmd)))
			swap(&b);
        else if (!ft_strncmp("ra", cmd, ft_strlen(cmd)))
			rotate(&a);
        else if (!ft_strncmp("rb", cmd, ft_strlen(cmd)))
			rotate(&b);
        else if (!ft_strncmp("rra", cmd, ft_strlen(cmd)))
			reverse_rotate(&a);
        else if (!ft_strncmp("rrb", cmd, ft_strlen(cmd)))
			reverse_rotate(&b);
        else if (!ft_strncmp("ss", cmd, ft_strlen(cmd)))
        {
        	swap(&a);
        	swap(&b);
        }
        else if (!ft_strncmp("rr", cmd, ft_strlen(cmd)))
        {
        	rotate(&a);
        	rotate(&b);
        }
        else if (!ft_strncmp("rrr", cmd, ft_strlen(cmd)))
        {
        	reverse_rotate(&a);
        	reverse_rotate(&b);
        }
        else
        {
			exception();
			free(cmd);
        }
        /*
        write(1, "A: ", 3);
        printLinkedList(a);
        write(1, "B: ", 3);
        printLinkedList(b);
        write(1, "---------------\n", 16);
         */
		free(cmd);
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
		while (argc--)
		{
			if (ft_strlen(argv[argc]) == 0)
				exception();
		}
		parse_parameters(argv);
		fill_list(argv, &stack_a);
		checkLinkedList(stack_a);
		do_actions(stack_a, stack_b);
	}
	return (0);
}