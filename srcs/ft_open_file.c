/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 18:14:52 by atammie           #+#    #+#             */
/*   Updated: 2019/10/30 18:14:54 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
# include <stdio.h>

uint64_t	*ft_open_file(int fd, int *i)
{
	int 	red;
	int 	k;
	char 	buf[22];
	uint64_t *ll;

	ll = (uint64_t*)ft_memalloc(27 * sizeof(uint64_t));
	ft_bzero((void*)ll, 27);
	k = *i;
	while ((red = read(fd, buf, 21)) >= 20 && k != 27)
	{
		buf[red] = '\0';
		ll[k] = ft_bit_term(buf, red);
		if (!(ft_check_valid(ll[k])))
		{
			ft_putstr("Error");
			exit(0);
		}
		k++;
	}
	*i = k;
	return (ll);
}

uint64_t	ft_bit_term(char const *tmp, const int red)
{
	int i;
	int lb;
	int	line;
	uint64_t term;

	term = 0;
	i = 0;
	lb = 0;
	line = 0;
	while (i != red)
	{
		if (tmp[i] == '#') {
			term = term | ((uint64_t) 1 << (63 - i + lb - line));
		}
		if (tmp[i] == '\n') {
			lb++;
			line+=12;
		}
		i++;
	}
	term <<= (16 * ft_height_shift(tmp) + ft_width_shift(tmp));
	return (term);
}
