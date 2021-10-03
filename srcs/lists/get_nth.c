#include "push_swap.h"

/**
 * Функция возвращает указатель на
 * элемент списка c индексом n.
 *
 * @return
 * Возвращает указатель элемент
 * списка c индексом n.\n
 * Если список равен NULL - возвращается NULL.
 */
t_stack	*get_nth(t_stack *stack, int n)
{
	if (!stack)
		return (NULL);
	while (stack->next)
	{
		if (stack->ind == n)
			return (stack);
		stack = stack->next;
	}
	return (stack);
}