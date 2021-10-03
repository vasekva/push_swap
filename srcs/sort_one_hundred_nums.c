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

static void	find_range_numbers(t_stack **stack_a, t_stack **stack_b,
								  int range_size, int i)
{
	int range = range_size * i;
	int	minRangeValue;
	int	maxRangeValue;

	if (range <= 20)
	{
		minRangeValue = (*stack_a)->min_value;
		maxRangeValue = (*stack_a)->max_value;
	}
	else {
		minRangeValue = (*stack_a)->min_value + range_size * (i - 1);
		maxRangeValue = minRangeValue + range_size - 1;
	}
	//printf("Range #%d: %d - %d;\n", i, minRangeValue, maxRangeValue);
	i = 0;
	while (i++ < range_size)
	{
		int frontInd = find_first_val_front(*stack_a, minRangeValue, maxRangeValue);
		//printf("FrontInd: %d\n", frontInd);
		int backInd = find_first_val_back(*stack_a, frontInd, minRangeValue, maxRangeValue);
		//printf("BackInd: %d\n", backInd);
		//printf("Min: %d Max: %d\n", minRangeValue, maxRangeValue);

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
	int	amnt_of_nmbs;
	int	range_size;
	int	i;

	(*stack_a)->max_value = find_max_value(*stack_a);
	(*stack_a)->min_value = find_min_value(*stack_a);
	//printf("%d\n", max);
	//printf("%d\n", min);
	amnt_of_nmbs = (*stack_a)->max_value - (*stack_a)->min_value + 1;
	//printf("Number of values between them: %d\n", amnt_of_nmbs);

	int len = listLength(*stack_a);
	if (len <= 20)
		range_size = len;
	else
		range_size = amnt_of_nmbs / (listLength(*stack_a) / 20);
	//if (listLength(*stack_a) % 20 > 0)
	//	++range_size;
	//printf("RangeSize: %d\n", range_size);

	i = 1;
	while ((*stack_a))
	{
		//TODO: ПРОВЕРИТЬ ЗАНОСЯТСЯ ЛИ ЧИСЛА ПО ГРУППАМ(RANGE)
		//TODO: Программа крашится при кол-во отличном от 500 и 100 - найти ошибку
		find_range_numbers(stack_a, stack_b, range_size, i++);
	}
	while (*stack_b)
		push(stack_b, stack_a, "a", 1);
}