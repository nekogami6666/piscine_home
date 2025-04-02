# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user <user@42.fr>                          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/02 00:00:00 by user              #+#    #+#              #
#    Updated: 2025/04/02 00:00:00 by user             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
	read_map.c \
	read_map_init.c \
	read_map_utils.c \
	solve_bsq.c \
	solve_bsq_utils.c \
	fill_and_print.c \
	free_mapinfo.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
