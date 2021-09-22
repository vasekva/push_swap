#include "push_swap.h"

void	printLinkedList(const t_stack *stack, int n)
{
    int i = -1;
    while (stack && ++i < n)
    {
        if (stack->next != NULL)
            printf("(%d [%d]) ", stack->value, stack->ind);
        else
            printf("(%d [%d])", stack->value, stack->ind);
        stack = stack->next;
    }
    printf("\n");
}
