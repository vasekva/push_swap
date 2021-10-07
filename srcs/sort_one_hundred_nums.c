#include "push_swap.h"

/**
 * Функция производит поиск числа сверху списка, диапазон
 * значений которого задан переменными от min_val до max_val.
 *
 * @param stack:	Стэк в котором происходит поиск.
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
	int	rotate_count_b;
	int	rotate_count_a;

	i = 0;
	rotate_count_b = 0;
	rotate_count_a = 0;
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

		// если индекс левой(верхней половины) меньше либо равен модулю индекса снизу(справа) и он
		// в первой половине чисел, либо во второй половине нет нужного числа
		if ((frontInd <= ft_abs(backInd) && frontInd >= 0) || backInd == 0)
		{
			rotate_count_a = frontInd * (-1);
		}
		else
		{
			rotate_count_a = backInd;
		}
		if (i <= 3 && listLength(*stack_b) <= 3)
		{
			scroll_to_past(stack_a, "a", rotate_count_a);
			push(stack_a, stack_b, "b", 1);
			if (i == 3)
				little_sort_reverse(stack_b);
		}
		else
		{
			rotate_count_b = push_from_a_to_b(stack_a, stack_b, rotate_count_a, rotate_count_b);
		}
	}
	scroll_to_past(stack_b, "b", rotate_count_b);
	rotate_count_b = 0;
}

void	sort_one_hundred_nums(t_stack **stack_a, t_stack **stack_b)
{
	int num_of_values;

	if (listLength(*stack_a) <= 100 && listLength(*stack_a) > 20)
		num_of_values = 9;
	else
		num_of_values = 20;

	int	minRangeValue;
	int	maxRangeValue;

	int	number_of_ranges;
	int size_of_range;
	int	len;
	int	i;

	int max = find_max_value(*stack_a);
	int min = find_min_value(*stack_a);

	len = listLength(*stack_a);
	if (len <= 10)
	{
		size_of_range = len;
		number_of_ranges = 1;
	}
	else
	{
		number_of_ranges = len / num_of_values;
		if (len % num_of_values != 0)
			number_of_ranges++;
		size_of_range = (max - min + 1) / number_of_ranges;
		size_of_range += 7;
	}
	i = 1;
	while (*stack_a)
	{
		(*stack_a)->range_size = size_of_range;
		if (listLength(*stack_a) <= 10)
		{
			minRangeValue = min;
			maxRangeValue = max;
		}
		else {
			minRangeValue = min + size_of_range * (i - 1);
			maxRangeValue = minRangeValue + size_of_range - 1;
		}
		find_range_numbers(stack_a, stack_b, minRangeValue, maxRangeValue);
		i++;
	}
	while (*stack_b)
		push(stack_b, stack_a, "a", 1);
}
