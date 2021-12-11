/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:32:34 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/11 19:23:41 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/hotrace.h"

static t_data	*ft_lstempty(void)
{
	t_data	*res;

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
	t_data	*last;

	last = ft_lstlast(begin);
	if (last && last->key && !last->value)
	{
		last->value = line;
		return (begin);
	}
	new = ft_lstempty();
	if (!new)
		return (NULL);
	new->key = line;
	++(*size);
	if (!begin)
		return (new);
	ft_lstadd_back(&last, new);
	return (begin);
}
