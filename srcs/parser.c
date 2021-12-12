/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 22:29:48 by adbenoit          #+#    #+#             */
/*   Updated: 2021/12/12 22:34:14 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static bool	handle_status(t_hashtab *hash_tab, size_t i)
{
	++hash_tab->status;
	if (i % 2)
		return (ft_perror(strerror(EINVAL), hash_tab->data));
	hash_tab->size /= 2;
	hash_tab->ptr = hash_data(hash_tab->data, hash_tab->size);
	if (!hash_tab->ptr)
		return (ft_perror(strerror(ENOMEM), hash_tab->data));
	return (0);
}

bool	parse_input(char *input, t_data **last, size_t n, t_hashtab *hash_tab)
{
	char	*line;
	size_t	i;

	line = input;
	i = -1;
	while (++i < n)
	{
		if (!line[0] && hash_tab->status == 0)
		{
			if (handle_status(hash_tab, i))
				return (1);
		}
		else
		{
			if (hash_tab->status == 0)
				++hash_tab->size;
			*last = hotrace(line, *last, *hash_tab);
			if (hash_tab->status == 0 && !(*last))
				return (ft_perror(strerror(ENOMEM), hash_tab->data));
			if (!hash_tab->data)
				hash_tab->data = *last;
		}
		line += ft_strlen(line) + 1;
	}
	return (0);
}
