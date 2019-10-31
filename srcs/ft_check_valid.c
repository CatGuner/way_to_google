/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 18:19:18 by atammie           #+#    #+#             */
/*   Updated: 2019/10/30 18:19:20 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int 	ft_check_valid(uint64_t term)
{
	if (term == 9223512776490647552ULL ||
		term == 17293822569102704640ULL ||
		term == 9223512777564356608ULL ||
		term == 13835128425100083200ULL ||
		term == 16141041801984212992ULL ||
		term == 2306089299818315776ULL ||
		term == 13835198794918002688ULL ||
		term == 4611756390392791040ULL ||
		term == 9223618327459397632ULL ||
		term == 16140936248867946496ULL ||
		term == 9223583144161050624ULL ||
		term == 6917740133873614848ULL ||
		term == 4611897126807404544ULL ||
		term == 13835163608398430208ULL ||
		term == 4611932309032009728ULL ||
		term == 4611897125733662720ULL ||
		term == 9223583145234792448ULL ||
		term == 16140971433240035328ULL ||
		term == 13835269161514696704ULL)
		return (1);
	return (0);
}
