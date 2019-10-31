/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freelinkedlist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <rofeldsp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 12:36:30 by rofeldsp          #+#    #+#             */
/*   Updated: 2019/10/31 18:29:49 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			freelist(t_filist *tetr)
{
	t_filist	*tmp;

	while (tetr != NULL)
	{
		tmp = tetr;
		tetr = tetr->prev;
		free(tmp);
	}
}
