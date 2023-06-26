NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -crs
RM = rm -f

SRCS = ft_printf.c\
		ft_numlen.c\
		ft_printhex.c\
		ft_printnbr.c\
		ft_printptr.c\
		ft_printstr.c\
		ft_printunsigned.c\
		ft_putchar.c

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
		$(AR) $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re