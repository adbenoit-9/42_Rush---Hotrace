/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:41:25 by adbenoit          #+#    #+#             */
/*   Updated: 2021/12/11 20:29:12 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

/* Calculates the hash of a string: polynomial rolling hash function. */
size_t	hash_code(const char *key)
{
	size_t	code;
	int		p;
	int		m;
	size_t	i;

	code = key[0];
	p = 97;
	m = 1e9 + 9;
	i = 1;
	while (key[i])
	{
		code += p * key[i];
		code %= m;
		p *= p;
		p %= m;
		++i;
	}
	return (code);
}

/* Puts the data in an array. */
t_data	**hash_data(t_data *data, size_t size)
{
	t_data	**hash_data;
	t_data	*curr_data;
	size_t	code;
	size_t	index;
	size_t	i;
	size_t	count;

	hash_data = (t_data **)malloc(sizeof(t_data *) * size);
	if (!hash_data)
		return (NULL);
	i = 0;
	count = 0;
	while (i < size)
	{
		hash_data[i] = 0;
		++i;
	}
	while (data)
	{
		curr_data = data;
		data = data->next;
		curr_data->next = NULL;
		code = hash_code(curr_data->key);
		index = code % size;
		if (hash_data[index])
		{
			++count;
			ft_lstadd_back(&hash_data[index], curr_data);
		}
		else
			hash_data[index] = curr_data;
	}
	//printf("count: %zu\n", count);
	return (hash_data);
}
