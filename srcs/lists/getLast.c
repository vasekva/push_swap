#include "push_swap.h"

/**
 * Функция возвращает указатель на
 * последний элемент списка.
 *
 * @return
 * Возвращает указатель на последний
 * элемент списка.\n
 * Если список равен NULL - возвращается NULL.
 */
t_stack	*getLast(t_stack *stack)
{
    if (!stack)
        return (NULL);
    while (stack->next)
        stack = stack->next;
    return (stack);
}