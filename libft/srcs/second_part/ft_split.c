/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 04:49:47 by jberegon          #+#    #+#             */
/*   Updated: 2020/11/11 22:22:34 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_count_words(char const *str, char c)
{
	size_t i;
	size_t words;

	i = 0;
	words = 0;
	while (str[i] != '\0')
	{
		if (words == 0 && str[i] != c)
			words++;
		if (str[i] == c && str[i + 1] != c && str[i + 1] != '\0')
		{
			words++;
		}
		i++;
	}
	return (words);
}

static void		ft_free_words(char **matrix, size_t num)
{
	if (num == 0)
		free(matrix);
	else
	{
		while ((num - 1) > 0)
		{
			free(matrix[num - 1]);
			num--;
		}
		free(matrix);
	}
}

static	void	ft_do_words(const char *str, char c, int i, char **matrix)
{
	size_t		arr_ind;
	int			len;
	int			start;

	arr_ind = 0;
	start = 0;
	while (arr_ind < ft_count_words(str, c))
	{
		while (str[i] && str[i] == c)
			i++;
		if (i == 0 || ((str[i] != c) && (str[i - 1] == c || str[i - 1] == '\0')))
			start = i;
		if (str[i + 1] == c || str[i + 1] == '\0')
		{
			len = i - start + 1;
			matrix[arr_ind++] = ft_substr(str, i - len + 1, len);
			if (!matrix[arr_ind - 1])
			{
				ft_free_words(matrix, arr_ind - 1);
				return ;
			}
		}
		i++;
	}
	matrix[arr_ind] = NULL;
}

char			**ft_split(char const *str, char symbol)
{
	char	**matrix_for_strings;
	int		num_words;
	int		ind;

	ind = 0;
	if (!str)
		return (NULL);
	num_words = ft_count_words(str, symbol);
	matrix_for_strings = (char **)malloc((num_words + 1) * sizeof(char *));
	if (!matrix_for_strings)
		return (NULL);
	ft_do_words(str, symbol, ind, matrix_for_strings);
	return (matrix_for_strings);
}
