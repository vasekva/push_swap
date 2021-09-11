#include "push_swap.h"

int	is_int_num(char *str)
{
	int	i;
	long long	number;

	i = -1;
	number = 0;
	// проверка на то, что строка - число
	while (str[++i])
	{
		if (i == 0 && str[i] == '-')
			continue ;
		if (str[i] == ' ')
			continue;
		if (!ft_isdigit(str[i]))
		{
			exception(NOTDIGIT);
		}
	}
	number = ft_atoi(str);
	if (number > 2147483647 || number < -2147483648)
		exception(OVERFLOW);
	return ((int)number);
}

int	parse_parameters(char **argv)
{
	int	i;

	i = 0;
	// проверка валидности чисел в массиве
	while (argv[++i])
	{
		is_int_num(argv[i]);
	}
	return (0);
}

t_stack	*getLast(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}

void	printLinkedList(const t_stack *stack, int n)
{
	int i = -1;
	while (stack && ++i < n)
	{
		if (stack->next != NULL)
			printf("%d ", stack->value);
		else
			printf("%d", stack->value);
		stack = stack->next;
	}
	printf("\n");
}

int	listLength(const t_stack *stack)
{
	int length;

	length = 0;
	while (stack)
	{
		stack = stack->next;
		length++;
	}
	return (length);
}

void	checkLinkedList(const t_stack *stack)
{
	const t_stack	*p;
	const t_stack	*p_iter;

	p = stack;
	p_iter = stack;
	while (stack)
	{
		while (p_iter)
		{
			if (stack == p_iter)
				p_iter = p_iter->next;
			else
			{
				if (stack->value == p_iter->value)
					exception(REPEATING);
				p_iter = p_iter->next;
			}
		}
		p_iter = p; // обнуление указателя
		stack = stack->next;
	}
}

void	pushBack(t_stack **stack, int value)
{
	t_stack *last;
	t_stack *tmp;

	if (!(last = getLast(*stack)))
	{
		(*stack) = (t_stack *)malloc(sizeof(t_stack));
		(*stack)->value = value;
		(*stack)->next = NULL;
	}
	else
	{
		tmp = (t_stack *)malloc(sizeof(t_stack));
		tmp->value = value;
		tmp->next = NULL;
		last->next = tmp;
	}
}

int	has_spaces(const char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == ' ')
			return (1);
	}
	return (0);
}

void	fill_list(char **argv, t_stack **stack)
{
	char **arr;
	int	i;
	int j;

	i = 0;
	arr = NULL;
	while (argv[++i])
	{
		j = -1;
		if (has_spaces(argv[i]))
		{
			arr = ft_split(argv[i], ' ');
			while (arr[++j])
			{
				pushBack(stack, ft_atoi(arr[j]));
			}
		}
		else
			pushBack(stack, ft_atoi(argv[i]));
	}
}

int main(int argc, char **argv)
{
	t_stack *stack;
	t_stack	*two;

	stack = NULL;
	pushBack(&two, 3);
	if (argc >= 2)
	{
		parse_parameters(argv);
		fill_list(argv, &stack);
		checkLinkedList(stack);
		printLinkedList(stack, listLength(stack));
		swap(&stack);
		swap(&two);
		printLinkedList(stack, listLength(stack));
		printLinkedList(two, listLength(two));
		push(&two, &stack);
		printLinkedList(stack, listLength(stack));
		printLinkedList(two, listLength(two));
		printf("Hello, World!\n");
	}
	else
		exception(FEWPARAMS);
	return 0;
}
