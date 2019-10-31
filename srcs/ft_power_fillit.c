/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power_fillit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:56:44 by atammie           #+#    #+#             */
/*   Updated: 2019/10/31 18:56:59 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

uint64_t		ftpow(uint64_t number, int power, t_filist *tetr)
{
	if (power == 2)
		return (number * number);
	else if (power == 1)
		return (number);
	else if (power == 0)
		return (1);
	return (number = number * tetr->power[power - 1]);
}
