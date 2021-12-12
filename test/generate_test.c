#include <libc.h>

int	main(int ac, char **av)
{
	if (ac != 3)
		write(2, "miss arg\n", 9);
	else
	{
		int nb_key = atoi(av[1]);
		int nb_search = atoi(av[2]);
		for (int i = 0;i <nb_key; i++ )
			printf("key_%d\nvalue_%d\n",i,i);
		printf("\n");
		for (int i = 0;i <nb_search; i++ )
			printf("key_%d\n", rand() % nb_key);
		// for (int i = nb_key; i < nb_key + nb_search; i++)
		// 	printf("key_%d\n", i);
	}
}