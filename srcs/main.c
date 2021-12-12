/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:41:57 by adbenoit          #+#    #+#             */
/*   Updated: 2021/12/12 22:01:47 by adbenoit         ###   ########.fr       */
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

bool	parse_input(char *input, t_data **last, size_t n, t_hashtab *hash_tab)
{
	char	*line;
	size_t	i;
	
	line = input;
	i = 0;
	while (i < n)
	{
		if (!line[0] && hash_tab->status == 0)
		{
			++hash_tab->status;
			if (i % 2)
				return (ft_perror(strerror(EINVAL), hash_tab->data));
			hash_tab->size /= 2;
			hash_tab->ptr = hash_data(hash_tab->data, hash_tab->size);
			if (!hash_tab->ptr)
				return (ft_perror(strerror(ENOMEM), hash_tab->data));
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
		++i;
	}
	return (0);
}

int	main(void)
{
	t_hashtab	hash_tab;
	size_t		end;
	char		*input;
	t_data  	*last;
	char		*ptr[10000];
	size_t		i;
	
	last = NULL;
	hash_tab.ptr = NULL;
	hash_tab.data = NULL;
	hash_tab.size = 0;
	hash_tab.status = 0;
	i = 0;
	input = read_file(STDIN_FILENO, &end);
	while (input)
	{
		ptr[i] = input;
		if (parse_input(input, &last, end, &hash_tab))
		{
			free_tab(ptr, i);
			clear_datatab(hash_tab.ptr, hash_tab.size);
			return (1);
		}
		end = 0;
		input = read_file(STDIN_FILENO, &end);
		++i;
	}
	free_tab(ptr, i);
	clear_datatab(hash_tab.ptr, hash_tab.size);
	return (0);
}
