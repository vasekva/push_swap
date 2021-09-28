#include "push_swap.h"

/**
 * Функция создает новый элемент с
 * переданным в параметры значением и
 * вставляет его в конец списка.
 * В новом элементе сохраняется указатель
 * на предыдущее значение и устанавливается
 * NULL для следующего.
 *
 * @param stack: Список, в который
 * производится вставка.
 *
 * @param value: Значение для вставки
 * в созданный элемент.
 */
void	pushBack(t_stack **stack, int value)
{
    t_stack *last;
    t_stack *tmp;

    if (!(last = getLast(*stack)))
    {
        (*stack) = (t_stack *)malloc(sizeof(t_stack));
        (*stack)->value = value;
        (*stack)->next = NULL;
		(*stack)->past = NULL;
    }
    else
    {
        tmp = (t_stack *)malloc(sizeof(t_stack));
        tmp->value = value;
        tmp->next = NULL;
		tmp->past = last;
        last->next = tmp;
    }
}