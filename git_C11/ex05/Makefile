# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/01 14:27:52 by haokumur          #+#    #+#              #
#    Updated: 2025/04/01 15:23:46 by haokumur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME	= do-op

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I include

SRC_DIR	= src
SRC		= $(SRC_DIR)/main.c \
		  $(SRC_DIR)/operations.c \
		  $(SRC_DIR)/ft_atoi.c \
		  $(SRC_DIR)/ft_putnbr.c \
		  $(SRC_DIR)/ft_putstr.c
OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
