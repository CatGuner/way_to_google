# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rofeldsp <rofeldsp@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/27 13:14:43 by rofeldsp          #+#    #+#              #
#    Updated: 2019/10/30 20:33:46 by atammie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= fillit

SRC_DIR	:= ./srcs
INC_DIR	:= ./includes
OBJ_DIR	:= ./obj
LIB_DIR	:= ./libft


SRC =   main.c \
		solver_1.c \
		solver_2.c \
		freelinkedlist.c \
		create_tetris.c \
		ft_sqrt_round.c \
		print_tetris.c \
		ft_power_fillit.c \
		ft_open_file.c \
		ft_param_shifts.c \
		ft_check_valid.c

OBJ		:= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

# compiler and flags
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror -pedantic -std=c99
OFLAGS	:= -pipe -flto
CFLAGS	+= $(OFLAGS)

# libraries

# include $(LIB_DIR)/libft.h

.PHONY: all clean fclean re $(NAME)

all: $(NAME)

$(NAME):
	mkdir -p $(OBJ_DIR)
	@$(MAKE) -C $(LIB_DIR)
	@$(MAKE) $(OBJ)
	gcc $(CFLAGS) $(OBJ) -L$(LIB_DIR) -lft -I$(INC_DIR) -I$(LIB_DIR) -o $(NAME)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	gcc $(CFLAGS) -I$(INC_DIR) -I$(LIB_DIR) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIB_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIB_DIR) fclean

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory

relibs:
	@$(MAKE) -C $(LIB_DIR) re --no-print-directory
	@$(MAKE) re --no-print-directory