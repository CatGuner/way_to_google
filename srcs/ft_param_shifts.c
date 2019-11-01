/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_shifts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 18:28:51 by atammie           #+#    #+#             */
/*   Updated: 2019/10/31 18:56:13 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_term_height(uint64_t term)
{
	int		count;
	unsigned long	aof;

	count = 0;
	aof = 0xF000000000000000;
	while (!(term & aof) && count != 4)
	{
		count++;
		aof >>= 16;
	}
	return (count);
}

int		ft_term_width(uint64_t term)
{
	int				count;
	unsigned long	aof;

	aof = 0x8000800080008000;
	count = 0;
	while (!(term & aof) && count != 4)
	{
		count++;
		aof >>= 1;
	}
	return (count);
}

int		ft_height_shift(const char *tmp)
{
	int		count;
	int		x;
	int		iter;

	x = 0;
	iter = 0;
	count = 0;
	while (iter != 20 && tmp[iter] != '#')
	{
		if (tmp[iter] == '.')
			x++;
		if (x == 4)
		{
			count++;
			x = 0;
		}
		iter++;
	}
	return (count);
}

int		ft_width_shift(const char *tmp)
{
	int		count;
	int		y;
	int		iter;

	y = 0;
	iter = 0;
	count = 0;
	while (tmp[iter] != '\n' && tmp[iter] != '#')
	{
		if (tmp[iter] == '.')
			y++;
		if (y == 3)
		{
			count++;
			y = 0;
			iter -= 14;
		}
		iter += 5;
	}
	return (count);
}
