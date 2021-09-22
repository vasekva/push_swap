#include "push_swap.h"

t_stack	*getLast(t_stack *stack)
{
    if (stack == NULL)
        return (NULL);
    while (stack->next)
    {
        stack = stack->next;
    }
    return (stack);
}