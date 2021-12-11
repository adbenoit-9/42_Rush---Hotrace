/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 18:50:39 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/11 19:03:23 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/hotrace.h"

static void	clean_data(t_data *data)
{
	if (data)
	{
		free(data->key);
		free(data->value);
		free((void *)data);
	}
}

void	clear_tab(t_data **begin, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		clean_data(begin[i]);
}
