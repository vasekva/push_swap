#include "push_swap.h"

/**
 * Функция производит поиск числа сверху списка, диапазон
 * значений которого задан переменными от min_val до max_val.
 *
 * @param stack:	Стэк в котором происходит поис.
 * @param min_val:	минимальное значения диапазона.
 * @param max_val:	максимальное значение диапазона.
 *
 * @return	Возвращает индекс искомого числа, найденного
 * при проходке сверху списка.\n
 * Если индекс заходит на вторую половину списка - поиск прекращается
 */
int	find_first_val_front(t_stack *stack, int min_val, int max_val)
{
	t_stack *tmp;

	tmp = stack;
	while (tmp && tmp->ind >= 0)
	{
		if (tmp->value >= min_val && tmp->value <= max_val)
			return (tmp->ind);
		tmp = tmp->next;
	}
	return (0);
}

/**
 * Функция производит поиск числа снизу списка, диапазон
 * значений которого задан переменными от min_val до max_val
 * Если функция доходит до индекса, заданного переменной
 * frontInd или до первой половины стека - поиск прекращается.
 *
 * @param stack :	Стэк в котором происходит поиск.
 * @param min_val :	минимальное значения диапазона.
 * @param max_val : максимальное значение диапазона.
 *
 * @return	Возвращает индекс искомого числа, найденного
 * при проходке снизу списка.
 */
int	find_first_val_back(t_stack *stack, int frontInd, int min_val, int max_val)
{
	t_stack *tmp;

	tmp = getLast(stack);
	while (tmp && tmp->ind != frontInd && tmp->ind < 0)
	{
		if (tmp->value >= min_val && tmp->value <= max_val)
			return (tmp->ind);
		tmp = tmp->past;
	}
	return (0);
}

static void	find_range_numbers(t_stack **stack_a, t_stack **stack_b, int range_size)
{
	int i;

	i = 0;
	// Вычисление 5ти диапазонов значений исходя
	// из максимального и минимального числа в списке
	while (++i <= 1)
	{
		int range = range_size * i;
		int	minRangeValue = range_size * i - range_size;
		int	maxRangeValue = range - 1;
		//printf("Range #%d: %d - %d;\n", i, minRangeValue, maxRangeValue);
		int frontInd = find_first_val_front(*stack_a, minRangeValue, maxRangeValue);
		//printf("FrontInd: %d\n", frontInd);
		int backInd = find_first_val_back(*stack_a, frontInd, minRangeValue, maxRangeValue);
		//printf("BackInd: %d\n", backInd);

		// если оба индекса равны 0 и значение под этим индексом
		// не в диапазоне значений - число не найдено
		if (frontInd == 0 && backInd == 0 && ((*stack_a)->value <= minRangeValue
			|| (*stack_a)->value >= maxRangeValue))
				continue;
		else
		{
			// если число найдено только в одной половине стека
			if (backInd == 0 || frontInd == 0)
			{
				if (backInd == 0)
					rotate(stack_a, "a", frontInd);
				else
					reverse_rotate(stack_a, "a", ft_abs(backInd));
			}
			else
			{
				// если индекс сверху меньше либо равен модулю индекса снизу и он
				// в первой половине чисел
				if (frontInd <= ft_abs(backInd) && frontInd >= 0)
					rotate(stack_a, "a", ft_abs(frontInd));
				else
					reverse_rotate(stack_a, "a", ft_abs(backInd));
			}
		}
	}
}

void	sort_one_hundred_nums(t_stack **stack_a, t_stack **stack_b)
{
	int	max;
	int	min;
	int	amnt_of_nmbs;
	int	range_size;

	push(stack_a, stack_b, "b", 3);
	little_sort_reverse(stack_b);

	//int count = 9;
	//int count = 14;
	//int count = 16;
	while ((*stack_a))
	//while (count--)
	{
		max = find_max_value(*stack_a);
		min = find_min_value(*stack_a);
		//printf("%d\n", max);
		//printf("%d\n", min);
		amnt_of_nmbs = max - min + 1;
		//printf("Number of values between them: %d\n", amnt_of_nmbs);
		range_size = amnt_of_nmbs / 5;
		//printf("Range of values in each group: %d\n", range_size);

		find_range_numbers(stack_a, stack_b, range_size);
		//todo: сделать вычисление позиции вставки числа из стека a в b
		//TODO: ПРОВЕРИТЬ ЗАНОСЯТСЯ ЛИ ЧИСЛА ПО ГРУППАМ(RANGE)
		//printLinkedList(*stack_a);
		//printLinkedList(*stack_b);
		push_stack_b(stack_a, stack_b);
	}

	while (*stack_b)
		push(stack_b, stack_a, "a", 1);

}