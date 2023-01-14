# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 11:21:07 by amsaoub           #+#    #+#              #
#    Updated: 2023/01/14 11:48:41 by amsaoub          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long
HEADER = so_long.h

SRC = backtraking.c \
	get_next_line_utils.c \
	parsing.c \
	so_long_tools.c  \
	get_next_line.c \
	libf.c \
	so_long.c \


CC = cc
CFLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit
RM = rm -rf

all: $(NAME)

$(NAME): $(SRC) $(HEADER)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean
	$(RM) $(BONUS)

re: fclean all