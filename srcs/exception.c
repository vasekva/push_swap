#include "push_swap.h"

void	exception(char *str)
{
	write (2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(1);
}