/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:41:25 by adbenoit          #+#    #+#             */
/*   Updated: 2021/12/11 16:44:37 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

size_t  hash_code(const char *key)
{
    size_t  code;
    int     p;
    int     m;
    size_t  i;

    code = key[0];
    p = 97;
    m = 1e9 + 9;
    i = 1;
    while (key[i])
    {
        code += p * key[i];
        code %= m;
        p *= p;
        p %= m;
        ++i;
    }
    // printf("\033[33mcode: %zu\033[0m\n", code);
    return (code);
}

size_t  hash_index(t_data **data, size_t code, size_t size)
{
    size_t  index;

    index = code % size;
    while (data[index])
    {
        ++code;
        index = code % size;
        
    }
    // printf("\033[34mindex: %zu\033[0m\n", index);
    return (index);
}

t_data  **hash_data(t_data *data, size_t size)
{
    t_data  **hash_data;
    size_t  code;
    size_t  index;
    size_t  i;

    hash_data = (t_data **)malloc(sizeof(t_data *) * size);
    if (!hash_data)
        return (NULL);
    i = 0;
    while (i < size)
    {
        hash_data[i] = 0;
        ++i;
    }
    while (data)
    {
        code = hash_code(data->key);
        index = hash_index(hash_data, code, size);
        hash_data[index] = data;
        data = data->next;
    }
    return (hash_data);
}
