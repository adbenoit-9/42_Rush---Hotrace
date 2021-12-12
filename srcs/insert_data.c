/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:13:32 by adbenoit          #+#    #+#             */
/*   Updated: 2021/12/12 19:13:34 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

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

t_data	*insert_data(t_data *last, char *line)
{
	t_data	*new;

	if (last && last->key && !last->value)
	{
		last->value = line;
		return (last);
	}
	new = ft_lstempty();
	if (!new)
		return (NULL);
	new->key = line;
	if (last)
		last->next = new;
	return (new);
}
