# include "push_swap.h"

/**
 * Функция возвращает
 * длину полученного списка.
 */
int	listLength(const t_stack *stack)
{
    int length;

    length = 0;
    while (stack)
    {
        stack = stack->next;
        length++;
    }
    return (length);
}