#include "push_swap.h"

/**
 * Функция ищет максимальное
 * значение в списке.
 *
 * @param stack: Список, в котором
 * производится поиск.
 *
 * @return
 * Возвращает максимальное значение.
 */
int	find_max_value(t_stack *stack)
{
	int	max;

	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}