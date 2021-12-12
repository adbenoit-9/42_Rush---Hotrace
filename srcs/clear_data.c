/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:45:35 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/12 15:13:12 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/hotrace.h"

void	clear_data(t_data *begin)
{
	t_data	*tmp;

	while (begin)
	{
		tmp = begin;
		begin = begin->next;
		free(tmp);
	}
}
