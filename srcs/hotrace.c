/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:51:59 by adbenoit          #+#    #+#             */
/*   Updated: 2021/12/12 23:02:54 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

t_data	*hotrace(char *line, t_data *last, t_hashtab *hash_tab)
{
	char	*value;
	size_t	len;

	value = NULL;
	if (hash_tab->status == 0)
		last = insert_data(last, line);
	if (hash_tab->status == 1)
	{
		if (hash_tab->ptr)
			value = search(line, hash_tab->ptr, hash_tab->size);
		if (value)
		{
			len = ft_strlen(value);
			value[len] = '\n';
			write(STDOUT_FILENO, value, len + 1);
			value[len] = 0;
		}
		else
		{
			write(STDOUT_FILENO, line, ft_strlen(line));
			write(STDOUT_FILENO, ": Not found.\n", 13);
		}
	}
	return (last);
}
