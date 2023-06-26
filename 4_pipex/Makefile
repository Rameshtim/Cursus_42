SOURCES = pipex.c pipex_utils.c
OBJECTS = $(SOURCES:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = pipex.h
LIBFT = ./libft/libft.a

all: pipex

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

pipex : ${OBJECTS} ${HEADER} libft
	$(CC) -o $@ $(OBJECTS) -L./libft -lft

libft:
	make -C ./libft

clean:
	rm -f $(OBJECTS)
	make -C ./libft clean

fclean: clean
	rm -f pipex $(LIBFT)
	make -C ./libft fclean

re: fclean all

.PHONY: all libft clean fclean re
