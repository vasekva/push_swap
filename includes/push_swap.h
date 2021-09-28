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
	int             ind;
	struct s_list	*next;
	struct s_list	*past;
}					t_stack;

void	exception(char *str);
int		get_next_line(int fd, char **line);

/*
 * FUNCTIONS FOR LISTS
 */
void	printLinkedList(const t_stack *stack, int len);
int	    listLength(const t_stack *stack);
t_stack *getLast(t_stack *stack);
void	pushBack(t_stack **stack, int value);
void    put_indexes(t_stack *stack);
int	find_max_value(t_stack *stack);
int	find_min_value(t_stack *stack);

void	little_sort(t_stack **stack);
void	sort_three_values(int ind_min, int ind_max, t_stack **stack, char *stack_name);


void	sort_five_and_four_nums(t_stack **stack_a, t_stack **stack_b);
void	sort_one_hundred_nums(t_stack **stack_a, t_stack **stack_b);


void	swap(t_stack **stack_a, char *name);
void	push(t_stack **src, t_stack **dst, char *name);
void	rotate(t_stack **stack, char *name);
void	reverse_rotate(t_stack **stack, char *name);
void    execute_two_cmds(char *cmd, t_stack **a, t_stack **b);


/*
 * UTILS.C
 */
int	get_modulus(int number);


#endif