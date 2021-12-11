/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:36:16 by adbenoit          #+#    #+#             */
/*   Updated: 2021/12/11 14:04:14 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "get_next_line/get_next_line.h"

# define STOREDATA 0
# define RESEARCH 1

typedef struct s_data
{
    char            *key;
    char            *value;
    struct s_data   *next;
}               t_data;

size_t  ft_strlen(const char *s);
int     ft_strcmp(const char *s1, const char *s2);
t_data  *store_data(t_data *begin, char *line);
char    *search(char *key);

#endif
