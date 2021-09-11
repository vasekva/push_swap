/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 07:18:14 by jberegon          #+#    #+#             */
/*   Updated: 2021/09/02 07:18:15 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

/*
 * FIRST_PART
 */
size_t		ft_strlen(const char *s);
int			ft_isdigit(int c);
long long	ft_atoi(const char *str);

/*
 * SECOND_PART
 */
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);


#endif