#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>

#include "../libft/includes/libft.h"
#include "exception.h"

typedef struct	t_number
{
	int	ind;
	int	number;
}				s_number;

void	exception(char *str);


#endif