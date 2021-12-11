/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_data_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:13:02 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/11 15:49:31 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/hotrace.h"

int	main(void)
{
	size_t	inc;
	t_data	*data;
	char		*line;
	t_data	*head;

	inc = 0;
	data = NULL;
	int	fd = open("srcs/tests/test.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
		data = store_data(data, line, &inc);
	printf("\nfd:%d, %zu", fd, inc);
	head = data;
	while (data)
	{
		printf("\n{%s}, {%s}", data->key, data->value);
		data = data->next;
	}
	clear_data(head);
}