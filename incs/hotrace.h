/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:36:16 by adbenoit          #+#    #+#             */
/*   Updated: 2021/12/12 21:57:18 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include<stdbool.h>  

# define STOREDATA 0
# define RESEARCH 1
# define BUFFER_SIZE 100000

typedef struct s_data
{
	char			*key;
	char			*value;
	struct s_data	*next;
}				t_data;

typedef struct s_hashtab
{
	t_data	**ptr;
	t_data	*data;
	size_t	size;
	bool	status;
}				t_hashtab;

t_data	*insert_data(t_data *last, char *line);
char	*search(const char *key, t_data **data, size_t size);
size_t	hash_code(const char *key);
t_data	**hash_data(t_data *data, size_t size);
t_data	*hotrace(char *line, t_data *last, t_hashtab hash_tab);

/* UTILS */
int		ft_strcmp(const char *s1, const char *s2);
t_data	*ft_lstlast(t_data *lst);
void	ft_lstadd_back(t_data **alst, t_data *new);
char	*read_file(int fd, size_t *key_value);
void	clear_data(t_data *begin);
void	clear_datatab(t_data **begin, size_t size);
size_t	ft_strlen(const char *str);
bool	ft_perror(const char *error, t_data *data);

#endif
