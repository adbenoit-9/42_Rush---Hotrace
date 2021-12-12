/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:51:59 by adbenoit          #+#    #+#             */
/*   Updated: 2021/12/12 19:13:06 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static void	search_all_keys(char *key, t_data **hash_tab, size_t n, size_t size)
{
	char	*value;
	size_t	len;
	size_t	i;

	i = 0;
	while (i < n)
	{
		value = NULL;
		if (hash_tab)
			value = search(key, hash_tab, size);
		if (value)
		{
			len = ft_strlen(value);
			value[len] = '\n';
			write(STDOUT_FILENO, value, len + 1);
			value[len] = 0;
		}
		else
		{
			write(STDOUT_FILENO, key, ft_strlen(key));
			write(STDOUT_FILENO, ": Not found.\n", 13);
		}
		key += ft_strlen(key) + 1;
		++i;
	}
}

static t_data	*store_data(char **input, size_t n, size_t *i)
{
	t_data	*begin;
	t_data	*last;

	begin = NULL;
	last = NULL;
	while (*i < n && (*input)[0])
	{
		last = insert_data(last, *input);
		if (!last)
		{
			ft_perror(strerror(ENOMEM), begin);
			return (NULL);
		}
		++(*i);
		if (*i == 1)
			begin = last;
		(*input) += ft_strlen(*input) + 1;
	}
	return (begin);
}

bool	hotrace(char *input, size_t n)
{
	t_data	*data;
	t_data	**hash_tab;
	size_t	i;

	data = NULL;
	hash_tab = NULL;
	i = 0;
	data = store_data(&input, n, &i);
	if (!data && i != 0)
		return (1);
	if (i % 2)
		return (ft_perror(strerror(EINVAL), data));
	++input;
	++i;
	hash_tab = hash_data(data, i / 2);
	if (!hash_tab)
		return (ft_perror(strerror(ENOMEM), data));
	if (i < n)
		search_all_keys(input, hash_tab, n - i, i / 2);
	clear_datatab(hash_tab, i / 2);
	return (0);
}
