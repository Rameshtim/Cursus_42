
NAME        := miniRT
CC        := gcc
LIBMLX  := ./MLX42
HEADERS := -I $(LIBMLX)/include/MLX42
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm -Ofast
FLAGS    := -Wall -Wextra -Werror 

SRCS        :=      sources/parse/check_element.c \
                          sources/parse/check_input.c \
                          sources/parse/check_objects.c \
                          sources/parse/get_field.c \
                          sources/parse/ft_atod.c \
                          sources/parse/parse_scenes.c \
                          sources/parse/putters.c \
                          sources/parse/reallocs.c \
                          sources/parse/parse_objects.c \
                          sources/utility/free.c \
                          sources/utility/ft_constructor.c \
                          sources/utility/init.c \
                          sources/utility/put_pixel.c \
                          sources/utility/utils1.c \
                          sources/utility/utils2.c \
                          sources/utility/utils3.c \
                          sources/utility/vec_calc1.c \
                          sources/utility/vec_calc2.c \
                          sources/utility/vec_calc3.c \
                          sources/trace/ft_sphere.c \
                          sources/trace/ft_plane.c \
                          sources/trace/ft_cylinder.c \
						  sources/translate/translate.c \
						  sources/translate/traverse.c \
						  sources/translate/rotate.c \
                          sources/translate/rotate_calc.c \
                          libft/ft_lstclear_bonus.c \
                          libft/ft_strmapi.c \
                          libft/ft_lstdel_last.c \
                          libft/ft_strcmp.c \
                          libft/ft_itoa.c \
                          libft/ft_putstr_fd.c \
                          libft/ft_strisnumber.c \
                          libft/ft_strlcpy.c \
                          libft/ft_lst_get_data_last_node.c \
                          libft/ft_tolower.c \
                          libft/ft_atoi.c \
                          libft/ft_striteri.c \
                          libft/ft_lstlast_bonus.c \
                          libft/ft_lstnew_bonus.c \
                          libft/ft_isspace.c \
                          libft/ft_lst_sort_str.c \
                          libft/ft_putchar_fd.c \
                          libft/ft_lstdup.c \
                          libft/ft_toupper.c \
                          libft/ft_memchr.c \
                          libft/ft_isdigit.c \
                          libft/ft_putnbr_fd.c \
                          libft/ft_substr.c \
                          libft/ft_lstmap_bonus.c \
                          libft/ft_strrchr.c \
                          libft/ft_dlstadd_front.c \
                          libft/ft_strtrim_all.c \
                          libft/ft_strncmp.c \
                          libft/ft_lstiter_bonus.c \
                          libft/ft_lstclear_if.c \
                          libft/ft_lstdel_first.c \
                          libft/ft_strlen.c \
                          libft/ft_memcmp.c \
                          libft/ft_strnstr.c \
                          libft/ft_isalpha.c \
                          libft/ft_dlstclear.c \
                          libft/ft_strcpy.c \
                          libft/ft_lstadd_front_bonus.c \
                          libft/ft_strisspace.c \
                          libft/ft_memset.c \
                          libft/ft_isalnum.c \
                          libft/ft_strdup.c \
                          libft/ft_strlcat.c \
                          libft/ft_memmove.c \
                          libft/ft_strjoin.c \
                          libft/ft_lstsize_bonus.c \
                          libft/ft_isascii.c \
                          libft/ft_dlstdelone.c \
                          libft/ft_putendl_fd.c \
                          libft/ft_isprint.c \
                          libft/ft_memcpy.c \
                          libft/ft_calloc.c \
                          libft/ft_split.c \
                          libft/ft_lstadd_back_bonus.c \
                          libft/ft_dlstnew.c \
                          libft/ft_strtrim.c \
                          libft/free_arr.c \
                          libft/ft_lstdelone_bonus.c \
                          libft/ft_strchr.c \
                          libft/ft_bzero.c \
                          get_next_line/get_next_line.c \
                          get_next_line/get_next_line_utils.c \
                          main.c \
                          
OBJS        := $(SRCS:.c=.o)

%.o: %.c
	@$(CC) -o $@ -c $< $(HEADERS) $>


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -rf

${NAME}:	${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@${CC} ${OBJS} ${LIBS} ${HEADERS} -o ${NAME}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

all:		${NAME}

bonus:		all

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re
