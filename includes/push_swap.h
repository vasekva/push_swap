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
}					t_stack;

void	exception(char *str);
int		get_next_line(int fd, char **line);


/*
 * FUNCTIONS FOR LISTS
 */
void	printLinkedList(const t_stack *stack, int n);
int	    listLength(const t_stack *stack);
t_stack *getLast(t_stack *stack);
void	pushBack(t_stack **stack, int value);


void little_sort(t_stack *a, t_stack *b);


void	swap(t_stack **stack_a);
void	push(t_stack **src, t_stack **dst);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void    execute_two_cmds(char *cmd, t_stack **a, t_stack **b);

#endif