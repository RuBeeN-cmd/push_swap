NAME = push_swap
SRCS = main.c \
	parsing.c \
	parsing_bis.c \
	parsing_bis_bis.c \
	radix.c \
	radix_bis.c \
	stack_utils.c \
	instruction.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra -Ilibft
LIBFT = libft/
MAKE = make -C
LIBFTFLAGS = -Llibft -lft 
LIB = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIB) 
	$(CC) $(CFLAGS) $(SRCS) $(LIBFTFLAGS) -o $(NAME)

$(LIB):
	$(MAKE) $(LIBFT)

clean:
	$(MAKE) $(LIBFT) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) $(LIBFT) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
