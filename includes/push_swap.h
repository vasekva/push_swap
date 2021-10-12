/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 00:33:21 by jberegon          #+#    #+#             */
/*   Updated: 2021/10/13 00:33:23 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>

# include "../libft/includes/libft.h"
# include "exception.h"

typedef struct s_list
{
	int				value;
	int				range_size;
	int				val_ind_front;
	int				val_ind_back;
	int				cycle_index;
	int				ind;
	struct s_list	*next;
	struct s_list	*past;
}					t_stack;

/*
 * FUNCTIONS FOR LISTS
 */
int		find_max_value(t_stack *stack);
int		find_min_value(t_stack *stack);
t_stack	*get_last(t_stack *stack);
t_stack	*get_nth(t_stack *stack, int n);
int		list_length(const t_stack *stack);
void	push_back(t_stack **stack, int value);
void	put_indexes(t_stack *stack);
void	put_past_pointers(t_stack *stack);
int		find_put_ind(t_stack *stack, int required_number, int flag);

/*
 * ACTIONS.C
 */
void	swap(t_stack **stack_a, char *name, int count);
void	push(t_stack **src, t_stack **dst, char *name, int count);
void	rotate(t_stack **stack, char *name, int count);
void	reverse_rotate(t_stack **stack, char *name, int count);
void	execute_two_cmds(char *cmd, t_stack **a, t_stack **b, int count);

/*
 * BIG_SORT.C
 */
void	big_sort(t_stack **stack_a, t_stack **stack_b);

/*
 * EXCEPTION.C
 */
void	exception(char *str);

/*
 * INSERT_TO_B.C
 */
void	insert_to_b(t_stack **stack_a, t_stack **stack_b,
			int min_range_val, int max_range_val);

/*
 * LITTLE_SORT.C
 */
void	little_sort(t_stack **stack);

/*
 * LITTLE_SORT_REVERSE.C
 */
void	little_sort_reverse(t_stack **stack);

/*
 * PARSE_FUNCTIONS.C
 */
void	fill_list(char **argv, t_stack **stack);
void	checkLinkedList(const t_stack *stack);
int		parse_parameters(char **argv);

/*
 * PUSH_FROM_A_TO_B.C
 */
int		push_from_a_to_b(t_stack **stack_a, t_stack **stack_b,
			int rotate_count, int range_size);

/*
 * PUSH_STACK_B.C
 */
int		push_stack_b(t_stack **stack_a, t_stack **stack_b,
			int rotate_count_a, int rotate_count_b);

/*
 * SORT_FIVE_AND_FOUR_NUMS.C
 */
void	sort_five_and_four_nums(t_stack **stack_a, t_stack **stack_b);

/*
 * UTILS.C
 */
int		ft_abs(int number);
void	print_action_message(char *stack_name, char *action);
void	arr_free(char **array);
void	scroll_to_past(t_stack **stack, char *stack_name, int rotate_count);
void	scroll_stacks(t_stack **stack_a, t_stack **stack_b,
			int rotate_count_a, int rotate_count_b);

#endif
