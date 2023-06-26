NAME := libft.a
CFLAGS := -Werror -Wall -Wextra
CC := cc
files := ft_isalpha.c \
		ft_memchr.c \
		ft_split.c \
		ft_strlcpy.c \
		ft_strtrim.c \
		ft_atoi.c \
    	ft_isascii.c \
		ft_memcmp.c \
		ft_strchr.c \
		ft_strlen.c \
		ft_substr.c \
		ft_bzero.c \
		ft_isdigit.c \
		ft_memcpy.c \
		ft_strdup.c	\
		ft_strncmp.c \
		ft_tolower.c \
		ft_calloc.c \
		ft_isprint.c \
		ft_memmove.c \
		ft_strjoin.c \
		ft_strnstr.c \
		ft_toupper.c \
		ft_isalnum.c \
		ft_itoa.c \
		ft_memset.c \
		ft_strlcat.c \
		ft_strrchr.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \

files_bonus := ft_lstnew_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c \

object_files :=$(files:.c=.o)
object_files_bonus :=$(files_bonus:.c=.o)


$(NAME): $(object_files)
	ar -rcs $(NAME) $(object_files)
bonus: $(object_files_bonus)
	ar -rcs $(NAME) $(object_files_bonus)
all: $(NAME)
clean:
	rm -f $(object_files) $(object_files_bonus)
fclean:
	rm -f $(object_files) $(object_files_bonus)
	rm -f libft.a
re: fclean all
