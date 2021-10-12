/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 01:18:12 by jberegon          #+#    #+#             */
/*   Updated: 2021/10/08 01:18:14 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_int_num(char *str)
{
	int			i;
	long long	number;

	i = -1;
	while (str[++i])
	{
		if (i == 0 && str[i] == '-'
			&& ft_isdigit(str[i + 1]))
			continue ;
		if (!ft_isdigit(str[i]))
		{
			exception(NOTDIGIT);
		}
	}
	number = ft_atoi(str);
	if (number > 2147483647 || number < -2147483648)
		exception(OVERFLOW);
	return ((int)number);
}

static int	has_spaces(const char *str)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	while (str[++i])
	{
		if (str[i] != ' ')
			flag = 1;
	}
	if (!flag)
		exception("Error");
	i = -1;
	while (str[++i])
	{
		if (str[i] == ' ')
			return (1);
	}
	return (0);
}

int	parse_parameters(char **argv)
{
	int		i;
	int		j;
	char	**array;

	i = 0;
	j = -1;
	array = NULL;
	while (argv[++i])
	{
		if (has_spaces(argv[i]))
		{
			array = ft_split(argv[i], ' ');
			while (array[++j])
			{
				is_int_num(array[j]);
			}
			arr_free(array);
		}
		else
			is_int_num(argv[i]);
	}
	return (0);
}

void	checkLinkedList(const t_stack *stack)
{
	const t_stack	*p;
	const t_stack	*p_iter;

	p = stack;
	p_iter = stack;
	while (stack)
	{
		while (p_iter)
		{
			if (stack == p_iter)
				p_iter = p_iter->next;
			else
			{
				if (stack->value == p_iter->value)
					exception(REPEATING);
				p_iter = p_iter->next;
			}
		}
		p_iter = p;
		stack = stack->next;
	}
}

void	fill_list(char **argv, t_stack **stack)
{
	char	**arr;
	int		i;
	int		j;

	i = 0;
	arr = NULL;
	while (argv[++i])
	{
		j = -1;
		if (has_spaces(argv[i]))
		{
			arr = ft_split(argv[i], ' ');
			while (arr[++j])
			{
				push_back(stack, ft_atoi(arr[j]));
			}
			arr_free(arr);
		}
		else
			push_back(stack, ft_atoi(argv[i]));
	}
}
