#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>

#include "../libft/includes/libft.h"
#include "exception.h"

#ifndef BUFFER_SIZE
	# define BUFFER_SIZE 32
#endif

typedef struct		s_list
{
	int				value;
	int				range_size;
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
t_stack *getLast(t_stack *stack);
int	    listLength(const t_stack *stack);
void	printLinkedList(const t_stack *stack);
void	pushBack(t_stack **stack, int value);
void    put_indexes(t_stack *stack);
void	put_past_pointers(t_stack *stack);
t_stack	*get_nth(t_stack *stack, int n);


void	little_sort(t_stack **stack);
void	little_sort_reverse(t_stack **stack);

void	sort_five_and_four_nums(t_stack **stack_a, t_stack **stack_b);
int		find_put_ind(t_stack *stack, int required_number, int flag);


void	sort_one_hundred_nums(t_stack **stack_a, t_stack **stack_b);


void	swap(t_stack **stack_a, char *name, int count);
void	push(t_stack **src, t_stack **dst, char *name, int count);
void	rotate(t_stack **stack, char *name, int count);
void	reverse_rotate(t_stack **stack, char *name, int count);
void    execute_two_cmds(char *cmd, t_stack **a, t_stack **b, int count);


int	push_stack_b(t_stack **stack_a, t_stack **stack_b, int rotate_count_a, int rotate_count_b);
int	push_from_a_to_b(t_stack **stack_a, t_stack **stack_b, int rotate_count, int range_size);


/*
 * UTILS.C
 */
int	ft_abs(int number);
void	print_action_message(char *stack_name, char *action);
void	arr_free(char **array);
void	scroll_to_past(t_stack **stack, char *stack_name, int rotate_count);
void	scroll_stacks(t_stack **stack_a, t_stack **stack_b, int rotate_count_a, int rotate_count_b);

//33 12 3 -100 -150
#endif