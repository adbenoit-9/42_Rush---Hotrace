/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:30:18 by adbenoit          #+#    #+#             */
/*   Updated: 2021/12/12 16:19:54 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

/* Returns the value corresponding to the key.
Returns NULL if the key is not found. */
char	*search(const char *key, t_data **data, size_t size)
{
	size_t	index;
	size_t	code;
	t_data	*it;

	if (size == 0)
		return (NULL);
	code = hash_code(key);
	index = code % size;
	it = data[index];
	while (it && ft_strcmp(it->key, key) != 0)
	{
		++code;
		it = it->next;
	}
	if (!it)
		return (NULL);
	return (it->value);
}
