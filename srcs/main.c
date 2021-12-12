/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:41:57 by adbenoit          #+#    #+#             */
/*   Updated: 2021/12/12 16:37:20 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/hotrace.h"

static void	do_research(const char *key, t_data **hash_tab, size_t size)
{
	char	*value;
	size_t	len;

	value = NULL;
	if (hash_tab)
		value = search(key, hash_tab, size);
	if (value)
	{
		len = ft_strlen(value);
		value[len - 1] = '\n';
		write(STDOUT_FILENO, value, len);
		value[len - 1] = 0;
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
	t_data	*last;
	t_data	*begin;
	t_data	**hash_tab;
	size_t	i;
	size_t	size;
	char	*res;
	size_t	end;

	last = NULL;
	begin = NULL;
	hash_tab = NULL;
	i = 0;
	end = 0;
	res = read_file(STDIN_FILENO, &end);
	char	*begin_res = res;
	while (i < end && res[0])
	{
		last = store_data(last, res);
		if (i == 1)
			begin = last;
		res += ft_strlen(res) + 1;
		++i;
	}
	if (i % 2)
		// strerror
		write(STDERR_FILENO, "you cant have empty value\n", 27);
		clear_data(begin);
		free(begin_res);
		return (0);
	}
	size = i / 2;
	hash_tab = hash_data(begin, size);
	++res;
	++i;
	while (i < end)
	{
		do_research(res, hash_tab, size);
		res += ft_strlen(res) + 1;
		++i;
	}
	clear_datatab(hash_tab, size);
	free(begin_res);
}
