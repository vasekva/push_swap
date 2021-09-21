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
	struct s_list	*next;
}					t_stack;

void	exception(char *str);
int		get_next_line(int fd, char **line);


void	swap(t_stack **stack_a);
void	push(t_stack **src, t_stack **dst);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);


#endif