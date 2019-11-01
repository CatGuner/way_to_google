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
