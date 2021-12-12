/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:41:57 by adbenoit          #+#    #+#             */
/*   Updated: 2021/12/12 21:29:24 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int	main(void)
{
	size_t	end;
	size_t	i;
	int 	state;
	char	*input;
	char	*line;
	t_data  *begin;
	t_data  *last;
	t_data  **hash_tab;
	size_t	size;
	char	*ptr[10000];
	size_t	k;
	
	state = 0;
	size = 0;
	begin = NULL;
	last = NULL;
	hash_tab = NULL;
	i = 0;
	k = 0;
	input = read_file(STDIN_FILENO, &end);
	ptr[0] = input;
	while (input)
	{
		line = input;
		i = 0;
		while (i < end)
		{
			if (!line[0] && state == 0)
			{
				++state;
				if (i % 2)
					return (ft_perror(strerror(EINVAL), begin));
				size /= 2;
				hash_tab = hash_data(begin, size);
				if (!hash_tab)
					return (ft_perror(strerror(ENOMEM), begin));
			}
			else
			{
				if (state == 0)
					++size;
				last = hotrace(line, last, hash_tab, size, state);
				if (state == 0 && !last)
					return (ft_perror(strerror(ENOMEM), begin));
				if (!begin)
					begin = last;
			}
			line += ft_strlen(line) + 1;
			++i;
		}
		++k;
		end = 0;
		input = read_file(STDIN_FILENO, &end);
		ptr[k] = input;
	}
	i = 0;
	while (++i < k)
	{
		free(ptr[i]);
		++i;	
	}
	clear_datatab(hash_tab, size);
	return (0);
}
