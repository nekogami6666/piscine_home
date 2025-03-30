NAME = rush-02

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS_MAIN = main.c
SRCS_DICT = dictionary.c
SRCS_VALID = validation.c
SRCS_CONV_MAIN = conversion_main.c
SRCS_CONV_UTILS = conversion_utils.c
SRCS_CONV_PRINT_UTILS = conversion_print_utils.c
SRCS_CONV_PRINT_CHUNK = conversion_print_chunk.c
SRCS_STR = utils_str.c
SRCS_IO = utils_io.c

OBJS_MAIN = $(SRCS_MAIN:.c=.o)
OBJS_DICT = $(SRCS_DICT:.c=.o)
OBJS_VALID = $(SRCS_VALID:.c=.o)
OBJS_CONV_MAIN = $(SRCS_CONV_MAIN:.c=.o)
OBJS_CONV_UTILS = $(SRCS_CONV_UTILS:.c=.o)
OBJS_CONV_PRINT_UTILS = $(SRCS_CONV_PRINT_UTILS:.c=.o)
OBJS_CONV_PRINT_CHUNK = $(SRCS_CONV_PRINT_CHUNK:.c=.o)
OBJS_STR = $(SRCS_STR:.c=.o)
OBJS_IO = $(SRCS_IO:.c=.o)

OBJS = $(OBJS_MAIN) $(OBJS_DICT) $(OBJS_VALID) $(OBJS_CONV_MAIN) $(OBJS_CONV_UTILS) $(OBJS_CONV_PRINT_UTILS) $(OBJS_CONV_PRINT_CHUNK) $(OBJS_STR) $(OBJS_IO)

all: $(NAME)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re