/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tetris.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <rofeldsp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 12:36:37 by rofeldsp          #+#    #+#             */
/*   Updated: 2019/10/31 18:29:08 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				checkheight(t_filist *tetr)
{
	if ((tetr->tetromap & tetr->power[60]) != 0)
		return (1);
	if ((tetr->tetromap & 32768) != 0)
		return (4);
	if ((tetr->tetromap & 3221225472) != 0)
		return (3);
	else
		return (2);
}

int				checkwidth(t_filist *tetr)
{
	if ((tetr->tetromap & tetr->power[60]) != 0)
		return (4);
	if ((tetr->tetromap & 32768) != 0)
		return (1);
	if ((tetr->tetromap & 3221225472) != 0)
		return (2);
	else
		return (3);
}

t_filist		*addnode(uint64_t *t, t_filist *head, int tetrnum)
{
	t_filist	*tetr;
	int			i;

	tetr = (t_filist*)malloc(sizeof(t_filist));
	if (tetr == NULL)
		return (NULL);
	i = 0;
	while (i < 64)
	{
		tetr->power[i] = ftpow(2, i, tetr);
		i++;
	}
	tetr->tetromap = t[tetrnum];
	tetr->prev = head;
	tetr->next = NULL;
	tetr->line = 0;
	tetr->height = checkheight(tetr);
	tetr->width = checkwidth(tetr);
	tetr->buff = tetr->tetromap;
	return (tetr);
}

t_filist		*createstruct(uint64_t *t, int tetramount)
{
	t_filist	*tetr;
	int			i;

	tetr = (t_filist*)malloc(sizeof(t_filist));
	if ((i = -1) && tetr == NULL)
		return (NULL);
	tetr->tetromap = *t;
	tetr->prev = NULL;
	tetr->next = NULL;
	tetr->line = 0;
	while (++i < 64)
		tetr->power[i] = ftpow(2, i, tetr);
	tetr->height = checkheight(tetr);
	tetr->width = checkwidth(tetr);
	tetr->buff = tetr->tetromap;
	i = 0;
	while (++i < tetramount)
	{
		if (!(tetr->next = addnode(t, tetr, i)))
			return (NULL);
		tetr = tetr->next;
	}
	while (tetr->prev != NULL)
		tetr = tetr->prev;
	return (tetr);
}
