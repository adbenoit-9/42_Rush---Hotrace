/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:58:51 by adbenoit          #+#    #+#             */
/*   Updated: 2021/12/12 13:43:07 by pleveque         ###   ########.fr       */
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

static char	*trim_enter(char *str)
{
	int	size;

	size = ft_strlen(str) - 1;
	if (str[size] == '\n')
		str[size] = '\0';
	return (str);
}

char	*get_next_line_trim(int fd)
{
	char	*res;

	res = get_next_line(fd);
	if (res)
		res = trim_enter(res);
	return (res);
}
