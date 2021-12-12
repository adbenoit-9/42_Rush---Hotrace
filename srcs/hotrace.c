/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:51:59 by adbenoit          #+#    #+#             */
/*   Updated: 2021/12/12 21:09:21 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

t_data	*hotrace(char *line, t_data *last, t_data **hash_tab, size_t size, int state)
{
	char	*value;
	size_t	len;
	
	value = NULL;
	if (state == 0)
		last = insert_data(last, line);
	if (state == 1)
	{
		if (hash_tab)
			value = search(line, hash_tab, size);
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
