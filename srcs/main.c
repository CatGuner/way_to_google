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
		fd = open(av[1], O_RDONLY);
		tetro = ft_open_file(fd, &tetramount);
		body_of_prog(tetro, tetramount);
		free(tetro);
		return (0);
	}
	else
		exit(0);
}
