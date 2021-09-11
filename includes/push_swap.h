#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>

#include "../libft/includes/libft.h"
#include "exception.h"

typedef struct		s_list
{
	int				value;
	struct s_list	*next;
}					t_stack;

void	exception(char *str);

void	swap(t_stack **stack_a);
void	push(t_stack **src, t_stack **dst);


#endif