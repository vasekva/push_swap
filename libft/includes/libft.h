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
char		*ft_strdup(const char *s1);
char		*ft_strchr(const char *s, int c);
void		*ft_memcpy(void *dst, const void *src, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

/*
 * SECOND_PART
 */
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);


#endif