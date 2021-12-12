/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:58:51 by adbenoit          #+#    #+#             */
/*   Updated: 2021/12/12 16:06:17 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/hotrace.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

t_data	*ft_lstlast(t_data *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_data **alst, t_data *new)
{
	t_data	*temp;

	if (*alst)
	{
		temp = ft_lstlast(*alst);
		temp->next = new;
	}
	else
		*alst = new;
}

void	clear_data(t_data *begin)
{
	t_data	*tmp;

	while (begin)
	{
		tmp = begin;
		begin = begin->next;
		free(tmp);
	}
}

void	clear_datatab(t_data **begin, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		clear_data(begin[i]);
		++i;
	}
	free(begin);
}

size_t	ft_strlen(const char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		++i;
	return (i);
}