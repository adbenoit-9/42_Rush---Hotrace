/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:41:57 by adbenoit          #+#    #+#             */
/*   Updated: 2021/12/12 22:20:16 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	free_tab(char **ptr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(ptr[i]);
		++i;
	}
}

t_hashtab	init_hastab(void)
{
	t_hashtab	hash_tab;

	hash_tab.ptr = NULL;
	hash_tab.data = NULL;
	hash_tab.size = 0;
	hash_tab.status = 0;
	return (hash_tab);
}

bool	handle_status(t_hashtab *hash_tab, size_t i)
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

int	main(void)
{
	t_hashtab	hash_tab;
	size_t		nb[2];
	char		*input;
	t_data		*last;
	char		*ptr[10000];

	last = NULL;
	hash_tab = init_hastab();
	nb[0] = 0;
	nb[1] = 0;
	input = read_file(STDIN_FILENO, &nb[1]);
	while (input)
	{
		ptr[nb[0]++] = input;
		if (parse_input(input, &last, nb[1], &hash_tab))
		{
			free_tab(ptr, nb[0]);
			return (1);
		}
		nb[1] = 0;
		input = read_file(STDIN_FILENO, &nb[1]);
	}
	free_tab(ptr, nb[0]);
	clear_datatab(hash_tab.ptr, hash_tab.size);
	return (0);
}
