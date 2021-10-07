/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:40:22 by jberegon          #+#    #+#             */
/*   Updated: 2020/11/08 11:21:14 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi(const char *str)
{
	int			i;
	int			neg;
	long long	res;
	int			flag;

	flag = 0;
	i = 0;
	neg = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == 45 || str[i] == 43)
	{
		if (flag > 0)
			return (0);
		flag++;
		if (str[i] == 45)
			neg = -neg;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		res = res * 10 + str[i++] - '0';
	}
	return (res * neg);
}
