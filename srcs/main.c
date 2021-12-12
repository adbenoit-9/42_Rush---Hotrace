/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:41:57 by adbenoit          #+#    #+#             */
/*   Updated: 2021/12/12 19:09:42 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int	main(void)
{
	bool	ret;
	size_t	end;
	char	*input;

	end = 0;
	input = read_file(STDIN_FILENO, &end);
	if (!input)
	{
		ft_perror(strerror(ENOMEM), NULL);
		return (1);
	}
	ret = hotrace(input, end);
	free(input);
	return (ret);
}
