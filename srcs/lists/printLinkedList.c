#include "push_swap.h"

void	printLinkedList(const t_stack *stack, int n)
{
    int i = -1;
    while (stack && ++i < n)
    {
        if (stack->next != NULL)
            printf("%d ", stack->value);
        else
            printf("%d", stack->value);
        stack = stack->next;
    }
    printf("\n");
}
