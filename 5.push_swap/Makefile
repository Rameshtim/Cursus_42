
CC         =     gcc

CFLAGS     =     -Wall -Wextra -Werror
NAME     =    push_swap

CHECKER =    checker

LIBFT    =    libft/libft.a

SRCS     =      push_swap.c    \
            sort_small.c \
            radix_sort.c \
            utils.c \
            func_swap.c \
            func_rot.c \
            func_rerot.c\
            func_push.c\
            func_index.c\
            check_errors.c

OBJS    = $(SRCS:.c=.o)

all:    $(NAME)

$(NAME):    $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)

$(LIBFT):
	make -C libft

clean:
	make clean -C libft
	rm -rf $(OBJS)

fclean: clean
	rm -rf libft/libft.a
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re 
