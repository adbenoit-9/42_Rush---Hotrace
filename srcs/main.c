/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:41:57 by adbenoit          #+#    #+#             */
/*   Updated: 2021/12/11 16:07:35 by pleveque         ###   ########.fr       */
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
    size_t     size;

    state = STOREDATA;
    data = NULL;
    hash_tab = NULL;
    size = 0;
    while ((line = get_next_line(STDIN_FILENO)))
    {
        if (ft_strcmp(line, "\n") == 0)
        {
            printf("\033[31mend of storage\033[0m\n\n");
            hash_tab = hash_data(data, size);
            printf("data hashed\n");
            state = RESEARCH;
        }
        if (state == STOREDATA)
           data = store_data(data, line, &size);
        else
        {
            printf("search %s\n", line);
            value = search(line, hash_tab, size);
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
