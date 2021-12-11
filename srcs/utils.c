/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:58:51 by adbenoit          #+#    #+#             */
/*   Updated: 2021/12/11 16:59:51 by adbenoit         ###   ########.fr       */
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

void	ft_lstadd_front(t_data **alst, t_data *new)
{
	if (!new || !alst)
		return ;
	new->next = *alst;
	*alst = new;
	return ;
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
