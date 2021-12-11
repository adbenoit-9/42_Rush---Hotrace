/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:36:16 by adbenoit          #+#    #+#             */
/*   Updated: 2021/12/11 19:02:57 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "get_next_line.h"

# define STOREDATA 0
# define RESEARCH 1

typedef struct s_data
{
	char			*key;
	char			*value;
	struct s_data	*next;
}				t_data;

t_data	*store_data(t_data *begin, char *line, size_t *size);
char	*search(const char *key, t_data **data, size_t size);
size_t	hash_code(const char *key);
t_data	**hash_data(t_data *data, size_t size);
void	clear_data(t_data *begin);

/* UTILS */
int		ft_strcmp(const char *s1, const char *s2);
void	ft_lstadd_front(t_data **alst, t_data *new);
char	*get_next_line_trim(int fd);
void	ft_lstadd_back(t_data **alst, t_data *new);
t_data	*ft_lstlast(t_data *lst);

#endif
