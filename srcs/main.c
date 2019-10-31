/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:14:23 by atammie           #+#    #+#             */
/*   Updated: 2019/10/31 18:14:45 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				main(int ac, char **av)
{
	uint64_t	*tetro;
	int			fd;
	int			tetramount;

	if (ac == 2)
	{
		tetramount = 0;
		if (!(fd = open(av[1], O_RDONLY)))
		{
			ft_putstr("Missing file");
			exit(0);
		}
		tetro = ft_open_file(fd, &tetramount);
		if (tetramount == 0 || tetramount > 26)
		{
			ft_putstr("Error file");
			exit(0);
		}
		body_of_prog(tetro, tetramount);
		free(tetro);
		return (0);
	}
	else
	{
		ft_putstr("usage: ./fillit \"file name\"");
		exit(0);
	}
}
