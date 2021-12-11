/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:41:57 by adbenoit          #+#    #+#             */
/*   Updated: 2021/12/11 16:31:42 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/hotrace.h"

int main(void)
{
    char    *line;
    char    *value;
    int     state;
    t_data  *data;
    t_data  **hash_tab;
    size_t  size;

    state = STOREDATA;
    data = NULL;
    hash_tab = NULL;
    size = 0;
    while ((line = get_next_line_trim(STDIN_FILENO)))
    {
        if (state == STOREDATA && ft_strcmp(line, "") == 0)
        {
            printf("\033[31mend of storage - %zu items\033[0m\n", size);
            hash_tab = hash_data(data, size);
            printf("\033[32mdata hashed\033[0m\n\n");
            state = RESEARCH;
        }
        else if (state == STOREDATA)
           data = store_data(data, line, &size);
        else
        {
            printf("search |%s|\n", line);
            value = search(line, hash_tab, size);
            printf("ok\n");
            if (value)
                write(STDOUT_FILENO, value, ft_strlen(value));
            else
            {
                write(STDOUT_FILENO, line, ft_strlen(line));
                write(STDOUT_FILENO, ": Not found.\n", 13);
            }
        }
        
    }
    clear_data(data);
}
