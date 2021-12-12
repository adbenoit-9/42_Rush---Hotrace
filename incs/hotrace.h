/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:36:16 by adbenoit          #+#    #+#             */
/*   Updated: 2021/12/12 16:30:03 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

# define STOREDATA 0
# define RESEARCH 1
# define BUFFER_SIZE 100000

typedef struct s_data
{
	char			*key;
	char			*value;
	struct s_data	*next;
}				t_data;

t_data	*store_data(t_data *last, char *line);
char	*search(const char *key, t_data **data, size_t size);
size_t	hash_code(const char *key);
t_data	**hash_data(t_data *data, size_t size);

/* UTILS */
size_t	ft_strlen(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_lstadd_front(t_data **alst, t_data *new);
void	ft_lstadd_back(t_data **alst, t_data *new);
t_data	*ft_lstlast(t_data *lst);
char	*read_file(int fd, size_t *key_value);
void	clear_data(t_data *begin);
void	clear_datatab(t_data **begin, size_t size);

#endif
