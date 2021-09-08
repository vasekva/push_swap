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

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/*
 * FIRST_PART
 */
size_t			ft_strlen(const char *s);
int				ft_isdigit(int c);
long long		ft_atoi(const char *str);

/*
 * BONUSES
 */
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new_list);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new_list);
void			ft_lstdelone(t_list	*lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
								 void (*del)(void *));

#endif