#include "push_swap.h"

/**
 * Функция ищет минимальное
 * значение в списке.
 *
 * @param stack: Список, в котором
 * производится поиск.
 *
 * @return
 * Возвращает минимальное значение.
 */
int	find_min_value(t_stack *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}