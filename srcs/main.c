/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:41:57 by adbenoit          #+#    #+#             */
/*   Updated: 2021/12/11 20:07:06 by pleveque         ###   ########.fr       */
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
	char	*line;
	int		state;
	t_data	*last;
	t_data	*begin;
	t_data	**hash_tab;
	size_t	size;

	state = STOREDATA;
	last = NULL;
	begin = NULL;
	hash_tab = NULL;
	size = 0;
	line = get_next_line_trim(STDIN_FILENO);
	while (line)
	{
		if (state == STOREDATA && ft_strcmp(line, "") == 0)
		{
			if (last && !last->value)
			{
				write(STDIN_FILENO, "you cant have empty value\n", 27);
				clear_data(begin);
				return (0);
			}
			hash_tab = hash_data(begin, size);
			state = RESEARCH;
		}
		else if (state == STOREDATA)
		{
			last = store_data(last, line, &size);
			if (size == 1)
				begin = last;
		}
		else
			do_research(line, hash_tab, size);
		line = get_next_line_trim(STDIN_FILENO);
	}
	clear_data(begin);
	free(hash_tab);
}
