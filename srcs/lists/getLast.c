#include "push_swap.h"

/**
 * Function returns a pointer to the last
 * element of a list.
 *
 * @param stack: List whose pointer is returned.
 *
 * @return
 * Returns a pointer to the last
 * element of the passed list.\n
 * If stack equals NULL - returns NULL
 */
t_stack	*getLast(t_stack *stack)
{
    if (!stack)
        return (NULL);
    while (stack->next)
        stack = stack->next;
    return (stack);
}