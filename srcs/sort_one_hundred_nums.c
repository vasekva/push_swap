#include "push_swap.h"

/**
 * Функция производит поиск числа сверху списка, диапазон
 * значений которого задан переменными от min_val до max_val
 *
 * @param stack:	Стэк в котором происходит поиск
 * @param min_val:	минимальное значения диапазона
 * @param max_val:	максимальное значение диапазона
 *
 * @return	Возвращает индекс искомого числа, найденного
 * при проходке сверху списка
 */
int	find_first_val_front(t_stack *stack, int min_val, int max_val)
{
	t_stack *tmp;

	tmp = stack;
	while (tmp)
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
 * frontInd - поиск прекращается.
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
	while (tmp && tmp->ind != frontInd)
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
		printf("Range #%d: %d - %d;\n", i, minRangeValue, maxRangeValue);
		int frontInd = find_first_val_front(*stack_a, minRangeValue, maxRangeValue);
		printf("FrontInd: %d\n", frontInd);
		int backInd = find_first_val_back(*stack_a, frontInd, minRangeValue, maxRangeValue);
		printf("BackInd: %d\n", backInd);

		//todo: определить наивыгодное направление кручения стека

	}
}

void	sort_one_hundred_nums(t_stack **stack_a, t_stack **stack_b)
{
	int	max;
	int	min;
	int	amnt_of_nmbs;
	int	range_size;

	max = find_max_value(*stack_a);
	min	= find_min_value(*stack_a);
	printf("%d\n", max);
	printf("%d\n", min);
	amnt_of_nmbs = max - min + 1;
	printf("Number of values between them: %d\n", amnt_of_nmbs);
	range_size = amnt_of_nmbs / 5;
	printf("Range of values in each group: %d\n", range_size);

	find_range_numbers(stack_a, stack_b, range_size);
}