#include <stdio.h> // delete later
//#include "fillit.h"
#include "../includes/fillit.h"
#include <time.h> // убрать

int				main(int ac, char **av)
{
	int			i;
	clock_t		start, end;
	double 		cpu_time_used;
	char 		*map;
	uint64_t	*tetro;
	int			sqrsize;
	node		*tetr;
	char 		letter;
	int			fd;
	int 		tetramount;

	if (ac == 2) {
		tetramount = 0;
		fd = open(av[1], O_RDONLY);
		tetro = ft_open_file(fd, &tetramount);
		letter = 65;
		start = clock();
		if (!(tetr = createstruct(tetro, tetramount)))
			return (-1);
		if (!(sqrsize = deploy(tetr, tetramount)))
			return (-1);
		if (!(map = map_to_print(sqrsize)))
			return (-1);
		i = 0;
		while (i++ < tetramount) {
			map = fillfigure(map, tetr, sqrsize, letter);
			letter++;
			if (tetr->next != NULL)
				tetr = tetr->next;
		}
		freelist(tetr);
		ft_putstr(map);
		free(map);
		free(tetro);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("time %f\n", cpu_time_used);
		return (0);
	}
	else
		exit(0);
}
