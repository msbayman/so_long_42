# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 11:21:07 by amsaoub           #+#    #+#              #
#    Updated: 2023/01/21 17:30:02 by amsaoub          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long
NAMEB = so_long_bonus
HEADER = so_long.h
HEADERB = so_long_bonus.h

SRC = mandatory/backtraking.c \
	mandatory/get_next_line_utils.c \
	mandatory/parsing2.c \
	mandatory/parsing.c \
	mandatory/so_long_tools.c  \
	mandatory/get_next_line.c \
	mandatory/libf.c \
	mandatory/libf2.c \
	mandatory/libf3.c \
	mandatory/moves.c \
	mandatory/so_long.c \

BSRC = bonus/backtraking.c \
	bonus/get_next_line_utils.c \
	bonus/parsing2.c \
	bonus/parsing.c \
	bonus/so_long_tools.c  \
	bonus/so_long_tools2.c  \
	bonus/so_long_tools3.c  \
	bonus/get_next_line.c \
	bonus/libf.c \
	bonus/libf2.c \
	bonus/libf3.c \
	bonus/moves.c \
	bonus/so_long.c \


CC = cc
CFLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit
RM = rm -rf

all: $(NAME)

bonus : $(NAMEB)

$(NAME): $(SRC) $(HEADER)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

$(NAMEB): $(BSRC) $(HEADERB)
	$(CC) $(CFLAGS) $(BSRC) -o $(NAMEB)

clean:
	$(RM) $(NAME) $(NAMEB)

fclean: clean
	$(RM) $(bonus)

re: fclean all