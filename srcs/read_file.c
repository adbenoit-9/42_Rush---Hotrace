/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 13:58:35 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/12 23:02:15 by adbenoit         ###   ########.fr       */
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

static char	*iterate_file(char *res, int *i, size_t *key_value)
{
	while (res && res[++*i])
	{
		if (res[*i] == '\n')
		{
			if (res[*i + 1])
				++(*key_value);
			res[*i] = '\0';
		}
	}
	return (res);
}

char	*read_file(int fd, size_t *key_value)
{
	char	buffer[BUFFER_SIZE];
	char	*res;
	int		readed;
	int		i;

	res = NULL;
	readed = BUFFER_SIZE;
	while (readed == BUFFER_SIZE)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (ft_realloc_l_cat(buffer, readed, &res, ft_len(res)) == -1)
			return (NULL);
	}
	i = -1;
	if (!res[0])
	{
		free(res);
		return (NULL);
	}
	res = iterate_file(res, &i, key_value);
	*key_value += 1;
	return (res);
}
