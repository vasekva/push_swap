#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>

#include "../../libft/includes/libft.h"
#include "exception.h"

#ifndef BUFFER_SIZE
	# define BUFFER_SIZE 32
#endif

typedef struct		s_list
{
	int				value;
	int				range_size;
	int				val_ind_front;
	int 			val_ind_back;
	int				cycle_index;
	int             ind;
	struct s_list	*next;
	struct s_list	*past;
}					t_stack;

void	exception(char *str);
int		get_next_line(int fd, char **line);

/*
 * FUNCTIONS FOR LISTS
 */
int		find_max_value(t_stack *stack);
int		find_min_value(t_stack *stack);
t_stack *get_last(t_stack *stack);
int	    list_length(const t_stack *stack);
void	printLinkedList(const t_stack *stack);
void	push_back(t_stack **stack, int value);
void    put_indexes(t_stack *stack);
void	put_past_pointers(t_stack *stack);
t_stack	*get_nth(t_stack *stack, int n);


void	little_sort(t_stack **stack);
void	little_sort_reverse(t_stack **stack);

void	sort_five_and_four_nums(t_stack **stack_a, t_stack **stack_b);
int		find_put_ind(t_stack *stack, int required_number, int flag);

/*
 * BIG_SORT.C
 */
void	big_sort(t_stack **stack_a, t_stack **stack_b);


void	swap(t_stack **stack_a);
void	push(t_stack **src, t_stack **dst);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void    execute_two_cmds(char *cmd, t_stack **a, t_stack **b);


int	push_stack_b(t_stack **stack_a, t_stack **stack_b, int rotate_count_a, int rotate_count_b);
int	push_from_a_to_b(t_stack **stack_a, t_stack **stack_b, int rotate_count, int range_size);


/*
 * UTILS.C
 */
int		ft_abs(int number);
void	print_action_message(char *stack_name, char *action);
void	arr_free(char **array);
void	scroll_to_past(t_stack **stack, char *stack_name, int rotate_count);
void	scroll_stacks(t_stack **stack_a, t_stack **stack_b, int rotate_count_a, int rotate_count_b);
int		is_sorted(t_stack *stack);


/*
 * PARSE_FUNCTIONS.C
 */
void	fill_list(char **argv, t_stack **stack);
void	checkLinkedList(const t_stack *stack);
int		parse_parameters(char **argv);

/*
 * INSERT_TO_B.C
 */
void	insert_to_b(t_stack **stack_a, t_stack **stack_b,
					int min_range_val, int max_range_val);

#endif