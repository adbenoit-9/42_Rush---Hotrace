/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:41:57 by adbenoit          #+#    #+#             */
/*   Updated: 2021/12/12 15:20:05 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/hotrace.h"

static void	do_research(const char *key, t_data **hash_tab, size_t size)
{
	char	*value;

	if (!hash_tab)
	{
		write(STDOUT_FILENO, key, ft_strlen(key));
		write(STDOUT_FILENO, ": Not found.\n", 13);
		return ;
	}
	value = search(key, hash_tab, size);
	if (value)
	{
		write(STDOUT_FILENO, value, ft_strlen(value));
		write(STDOUT_FILENO, "\n", 1);
	}
	else
	{
		write(STDOUT_FILENO, key, ft_strlen(key));
		write(STDOUT_FILENO, ": Not found.\n", 13);
		return ;
	}
}

int	main(void)
{
	//char	*line;
	t_data	*last;
	t_data	*begin;
	t_data	**hash_tab;
	size_t	i;
	size_t	size;
	char	*res;
	size_t end_file;

	last = NULL;
	begin = NULL;
	hash_tab = NULL;
	i = 0;
	end_file = 0;
	res = read_file(STDIN_FILENO, &end_file);
	char	*begin_res = res;
	while (i < end_file && res[0])
	{
		last = store_data(last, res);
		if (i == 1)
			begin = last;
		res += ft_strlen(res) + 1;
		++i;
	}
	if (i % 2)
	{
		write(STDIN_FILENO, "you cant have empty value\n", 27);
		clear_data(begin);
		free(begin_res);
		return (0);
	}
	size = i /2;
	hash_tab = hash_data(begin, size);
	++res;
	++i;
	while (i < end_file)
	{
		do_research(res, hash_tab, size);
		res += ft_strlen(res) + 1;
		++i;
	}
	i = 0;
	while (i < size)
	{
		clear_data(hash_tab[i]);
		++i;
	}
	free(hash_tab);
	free(begin_res);
}
