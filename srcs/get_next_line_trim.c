/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_trim.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:14:53 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/11 16:35:10 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static char	*trim_enter(char *str)
{
	int	size;

	size = ft_strlen(str) - 1;
	if (str[size] == '\n')
		str[size] = '\0';
	return (str);
}

char	*get_next_line_trim(int fd)
{
	char	*res;

	res = get_next_line(fd);
	if (res)
		res = trim_enter(res);
	return (res);
}
