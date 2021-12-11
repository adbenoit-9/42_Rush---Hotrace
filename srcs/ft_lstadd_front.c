/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:21:31 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/11 14:54:19 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/hotrace.h"

void	ft_lstadd_front(t_data **alst, t_data *new)
{
	if (!new || !alst)
		return ;
	new->next = *alst;
	*alst = new;
	return ;
}
