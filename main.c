/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:41:57 by adbenoit          #+#    #+#             */
/*   Updated: 2021/12/11 14:05:30 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int main()
{
    char    *line;
    char    *value;
    int     state;
    t_data  *data;
    
    state = STOREDATA;
    data = NULL;
    while (line)
    {
        line = get_next_line(STDIN_FILENO);
        if (ft_strcmp(line, "/n") == 0)
            state = RESEARCH;
        if (state == STOREDATA)
           data = store_data(data, line);
        else
        {
            value = search(line);
            write(STDOUT_FILENO, value, ft_strlen(value));
        }
    }
    clear_data(data);
}
