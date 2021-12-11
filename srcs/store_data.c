/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:32:34 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/11 15:52:55 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/hotrace.h"

static t_data	*ft_lstempty()
{
	t_data *res;

	res = malloc(sizeof(t_data));
	if (!res)
		return (NULL);
	res->key = NULL;
	res->value = NULL;
	res->next = NULL;
	return (res);
}

t_data	*store_data(t_data *begin, char *line, size_t *size)
{
	t_data	*new;
	int		line_size;

	*size += 1;
	line_size = ft_strlen(line) - 1;
	if (line[line_size] == '\n')
		line[line_size] = '\0';
	if (begin && begin->key && !begin->value)
	{
		begin->value = line;
		return (begin);
	}
	new = ft_lstempty();
	if (!new)
		return (NULL);
	new->key = line;
	if (begin == NULL)
		return (new);
	ft_lstadd_front(&begin, new);
	return (begin);
}
