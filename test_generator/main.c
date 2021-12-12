#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

char	*ft_itoa(int n);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return(i);
}

int main (int ac, char **av) {
   int i, n, val;
	 int	fd;
	 char	*line;

	 if (ac < 1)
	 	n = 20000;
	else
		n = atoi(av[1]) * 2;
	 int	key[n / 2];
   
   /* Intializes random number generator */
	srand(time(NULL));
	fd = open("test.txt", O_CREAT | O_WRONLY | O_RDONLY);
	printf("%d", fd);
	for( i = 0 ; i < n ; i++ ) {
		val = rand() % 2147483647;
		line = ft_itoa(val);
		write(fd, line, ft_strlen(line));
		free(line);
		write(fd, "\n", 1);
		if (i % 2 == 0)
			key[i / 2] = val;
	}
	write(fd, "\n", 1);
	for( i = 0 ; i < n ; i++ )
	{
		// line = ft_itoa(key[rand() % n / 2]);
		line = ft_itoa(rand());
		write(fd, line, ft_strlen(line));
		free(line);
		write(fd, "\n", 1);
	}
  return(0);
}