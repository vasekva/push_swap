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
	while (stack && stack->ind >= 0)
	{
		if (stack->value >= min_val && stack->value <= max_val)
			return (stack->ind);
		stack = stack->next;
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
	while (stack && stack->ind != frontInd && stack->ind < 0)
	{
		if (stack->value >= min_val && stack->value <= max_val)
			return (stack->ind);
		stack = stack->past;
	}
	return (0);
}

static void	find_range_numbers(t_stack **stack_a, t_stack **stack_b, int minRangeValue, int maxRangeValue)
{
	int i;
	int range_size;

	i = 0;
	range_size = (*stack_a)->range_size;
	while (i++ < range_size && *stack_a)
	{
		int frontInd = find_first_val_front(*stack_a, minRangeValue, maxRangeValue);
		int backInd = find_first_val_back(*stack_a, frontInd, minRangeValue, maxRangeValue);

		// если оба индекса равны 0 и значение под этим индексом
		// не в диапазоне значений - число не найдено
		if (frontInd == 0 && backInd == 0 && ((*stack_a)->value < minRangeValue
			|| (*stack_a)->value > maxRangeValue))
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
		push_stack_b(stack_a, stack_b);
	}
}

void	sort_one_hundred_nums(t_stack **stack_a, t_stack **stack_b)
{
	int	minRangeValue;
	int	maxRangeValue;

	int	number_of_ranges;
	int size_of_range;
	int	len;
	int	i;

	int max = find_max_value(*stack_a);
	int min = find_min_value(*stack_a);

	len = listLength(*stack_a);
	if (len <= 20)
	{
		size_of_range = len;
		number_of_ranges = 1;
	}
	else
	{
		number_of_ranges = len / 20;
		if (len % 20 != 0)
			number_of_ranges++;
		size_of_range = (max - min + 1) / number_of_ranges;
	}
	i = 1;
	while ((*stack_a))
	{
		(*stack_a)->range_size = size_of_range;
		if (len <= 20)
		{
			minRangeValue = min;
			maxRangeValue = max;
		}
		else {
			minRangeValue = min + size_of_range * (i - 1);
			if (len % 20 != 0 && i == number_of_ranges)
				maxRangeValue = max;
			else
				maxRangeValue = minRangeValue + size_of_range - 1;
		}
		find_range_numbers(stack_a, stack_b, minRangeValue, maxRangeValue);
		i++;
	}
	while (*stack_b)
		push(stack_b, stack_a, "a", 1);

}