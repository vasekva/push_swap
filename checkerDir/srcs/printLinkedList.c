#include "push_swap.h"

/**
 * Функция выводит значения
 * полученного списка сверху вниз
 * (слева направо).
 */
void	printLinkedList(const t_stack *stack)
{
	while (stack)
	{
		if (stack->next != NULL)
			printf("%d ", stack->value);
		else
			printf("%d", stack->value);
		stack = stack->next;
	}
	printf("\n");
}
