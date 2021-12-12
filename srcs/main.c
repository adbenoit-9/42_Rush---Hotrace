/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:41:57 by adbenoit          #+#    #+#             */
/*   Updated: 2021/12/12 23:06:14 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static t_hashtab	init_hastab(void)
{
	t_hashtab	hash_tab;

	hash_tab.ptr = NULL;
	hash_tab.data = NULL;
	hash_tab.size = 0;
	hash_tab.status = 0;
	return (hash_tab);
}

static void	clean(char **ptr, t_hashtab hash_tab, size_t size)
{
	free_tab(ptr, size);
	clear_datatab(hash_tab.ptr, hash_tab.size);
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
		if (nb[0] < 10000)
			ptr[nb[0]++] = input;
		if (parse_input(input, &last, nb[1], &hash_tab))
		{
			free_tab(ptr, nb[0]);
			return (1);
		}
		nb[1] = 0;
		input = read_file(STDIN_FILENO, &nb[1]);
	}
	clean(ptr, hash_tab, nb[0]);
	return (0);
}
