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

int	parse_parameters(int argc, char **argv, t_list *list)
{
	int	i;
	int	j;

	i = 0;
	// проверка валидности чисел в массиве
	while (argv[++i])
	{
		is_int_num(argv[i]);
		if (argc > 2)
		{
			if (i == 1)
				list = ft_lstnew(&i);
			else
				list->next = ft_lstnew(&i);
		}
	}
	i = 0;
	// проверка повторяющихся чисел
	while (argv[++i])
	{
		j = 0;
		while (argv[++j])
		{
			if (j == i)
				continue;
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				exception(REPEATING);
		}
	}
}

t_list	*getLast(t_list *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
	{
		list = list->next;
	}
	return (list);
}

void	printLinkedList(const t_list *list)
{
	while (list)
	{
		if (list->next != NULL)
			printf("%d ", list->value);
		else
			printf("%d", list->value);
		list = list->next;
	}
	printf("\n");
}

void	pushBack(t_list **list, int value)
{
	t_list *last;
	t_list *tmp;

	if (!(last = getLast(*list)))
	{
		(*list) = (t_list *)malloc(sizeof(t_list));
		(*list)->value = value;
		(*list)->next = NULL;
	}
	else
	{
		tmp = (t_list *)malloc(sizeof(t_list));
		tmp->value = value;
		tmp->next = NULL;
		last->next = tmp;
	}
}

int	has_spaces(char *str)
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

int	fill_list(char **argv, t_list **list)
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
				pushBack(list, ft_atoi(arr[j]));
			}
		}
		else
			pushBack(list, ft_atoi(argv[i]));
	}
}

int main(int argc, char **argv)
{
	t_list *list;

	list = NULL;
	if (argc >= 2)
	{
		parse_parameters(argc, argv, &list);
		fill_list(argv, &list);
		printLinkedList(list);
		printf("Hello, World!\n");
	}
	else
		exception(FEWPARAMS);
	return 0;
}
