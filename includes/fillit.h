/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:13:17 by atammie           #+#    #+#             */
/*   Updated: 2019/10/31 18:13:21 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <stdint.h>
# include <fcntl.h>
# include "libft.h"

typedef struct		s_filist
{
	struct s_filist	*next;
	struct s_filist	*prev;
	uint64_t		tetromap;
	uint64_t		buff;
	uint64_t		power[64];
	int				line;
	int				height;
	int				width;
}					t_filist;

uint64_t			ftpow(uint64_t number, int power, t_filist *tetr);
int					ft_sqrt_round(int nb);
int					linebreak(t_filist *tetr, int sqrsize);
int					move(t_filist *tetr, int sqrsize);
int					checkmap(uint16_t *map, int sqrsize, t_filist *tetr);
int					moveprevnode(uint16_t *map, int sqrsize, t_filist *tetr);
int					fill_map(uint16_t *map, int sqrsize, t_filist *tetr);
uint16_t			*create_map(void);
t_filist			*move_tetrs_back(t_filist *tetr);
int					deploy(t_filist *tetr, int tetramount);
int					checkheight(t_filist *tetr);
int					checkwidth(t_filist *tetr);
char				*map_to_print(int sqrsize);
char				*fillfigure(char *map, t_filist *tetr,
								int sqrsize, char letter);
t_filist			*addnode(uint64_t *t, t_filist *head, int tetrnum);
void				freelist(t_filist *tetr);
t_filist			*createstruct(uint64_t *t, int tetramount);
uint64_t			*ft_open_file(int fd, int *i);
uint64_t			ft_bit_term(char const *tmp, const int red);
int					ft_check_valid(uint64_t term);
int					ft_term_height(uint64_t term);
int					ft_term_width(uint64_t term);
int					ft_height_shift(const char *tmp);
int					ft_width_shift(const char *tmp);
void				body_of_prog(uint64_t *tetro, int nt);

#endif
