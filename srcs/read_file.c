/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 13:58:35 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/12 15:06:01 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static int	ft_realloc_l_cat(char *src, int src_size, char **dst, int dst_size)
{
	char	*tmp;
	int		i;
	int		y;

	tmp = malloc(sizeof(char) * (src_size + dst_size + 1));
	if (!tmp)
		return (-1);
	i = 0;
	y = 0;
	while (i < dst_size)
	{
		tmp[i] = dst[0][i];
		i++;
	}
	while (y < src_size)
	{
		tmp[i + y] = src[y];
		y++;
	}
	tmp[dst_size + src_size] = '\0';
	free(*dst);
	*dst = tmp;
	return (dst_size + src_size);
}

static int	ft_len(char *str)
{
	if (!str)
		return (0);
	return (ft_strlen(str));
}

char	*read_file(int fd, size_t *key_value)
{
	char	buffer[BUFFER_SIZE];
	char	*res;
	int		readed;
	int		reading_type;

	reading_type = 1;
	res = NULL;
	readed = BUFFER_SIZE;
	while (readed == BUFFER_SIZE)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		ft_realloc_l_cat(buffer, readed, &res, ft_len(res));
	}
	int i = 0;
	while (res[i])
	{
		if (res[i] == '\n')
		{
			*key_value += 1;
			res[i] = '\0';
		}
		i++;
	}
	return (res);
}