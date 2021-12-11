/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:30:18 by adbenoit          #+#    #+#             */
/*   Updated: 2021/12/11 17:01:58 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

char	*search(const char *key, t_data **data, size_t size)
{
	size_t	index;
	size_t	begin;
	size_t	code;

	if (size == 0)
		return (NULL);
	code = hash_code(key);
	index = code % size;
	begin = index;
	while (ft_strcmp(data[index]->key, key) != 0)
	{
		++code;
		index = code % size;
		if (index == begin)
			return (NULL);
	}
	return (data[index]->value);
}
