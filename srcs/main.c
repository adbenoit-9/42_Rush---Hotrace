/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:41:57 by adbenoit          #+#    #+#             */
/*   Updated: 2021/12/11 15:51:15 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/hotrace.h"

int main()
{
    char    *line;
    // char    *value;
    int     state;
    t_data  *data;
		size_t			inc;
    
		inc = 0;
    state = STOREDATA;
    data = NULL;
    while ((line = get_next_line(STDIN_FILENO)))
    {
        if (ft_strcmp(line, "/n") == 0)
          state = RESEARCH;
        if (state == STOREDATA)
          data = store_data(data, line, &inc);
        // else
        // {
        //     value = search(line);
        //     write(STDOUT_FILENO, value, ft_strlen(value));
        // }
    }
    clear_data(data);
}
