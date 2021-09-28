#include "push_swap.h"

static void	find_range_numbers(t_stack **stack_a, t_stack **stack_b, int range_size)
{
	int i;

	i = 0;
	// Вычисление 5ти диапазонов значений исходя
	// из максимального и минимального числа в списке
	while (++i <= 5)
	{
		int range = range_size * i;
		int	minRangeValue = range_size * i - range_size;
		int	maxRangeValue = range - 1;
		printf("Range #%d: %d - %d;\n", i, minRangeValue, maxRangeValue);
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