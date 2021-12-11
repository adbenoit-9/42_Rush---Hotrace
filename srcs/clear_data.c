/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:45:35 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/11 16:34:00 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/hotrace.h"

static void	clean_data(t_data *data)
{
	free(data->key);
	free(data->value);
	free(data);
}

void	clear_data(t_data *begin)
{
	t_data	*tmp;

	while (begin)
	{
		tmp = begin;
		begin = begin->next;
		clean_data(tmp);
	}
}
