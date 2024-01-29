#  |  |  ___ \    \  |         |
#  |  |     ) |  |\/ |   _  |  |  /   _ 
# ___ __|  __/   |   |  (   |    <    __/ 
#    _|  _____| _|  _| \__,_| _|\_\ \___|
#                              by jcluzet
################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := libft.a
CC        := cc
FLAGS    := -Wall -Wextra -Werror 
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      ft_lstclear_bonus.c \
                          ft_strmapi.c \
                          ft_lstdel_last.c \
                          ft_strcmp.c \
                          ft_itoa.c \
                          ft_putstr_fd.c \
                          ft_strisnumber.c \
                          ft_strlcpy.c \
                          ft_lst_get_data_last_node.c \
                          ft_tolower.c \
                          ft_atoi.c \
                          ft_striteri.c \
                          ft_lstlast_bonus.c \
                          ft_lstnew_bonus.c \
                          ft_isspace.c \
                          ft_lst_sort_str.c \
                          ft_putchar_fd.c \
                          ft_lstdup.c \
                          ft_toupper.c \
                          ft_memchr.c \
                          ft_isdigit.c \
                          ft_putnbr_fd.c \
                          ft_substr.c \
                          ft_lstmap_bonus.c \
                          ft_strrchr.c \
                          ft_dlstadd_front.c \
                          ft_strtrim_all.c \
                          ft_strncmp.c \
                          ft_lstiter_bonus.c \
                          ft_lstclear_if.c \
                          ft_lstdel_first.c \
                          ft_strlen.c \
                          ft_memcmp.c \
                          ft_strnstr.c \
                          ft_isalpha.c \
                          ft_dlstclear.c \
                          ft_strcpy.c \
                          ft_lstadd_front_bonus.c \
                          ft_strisspace.c \
                          ft_memset.c \
                          ft_isalnum.c \
                          ft_strdup.c \
                          ft_strlcat.c \
                          ft_memmove.c \
                          ft_strjoin.c \
                          ft_lstsize_bonus.c \
                          ft_isascii.c \
                          ft_dlstdelone.c \
                          ft_putendl_fd.c \
                          ft_isprint.c \
                          ft_memcpy.c \
                          ft_calloc.c \
                          ft_split.c \
                          ft_lstadd_back_bonus.c \
                          ft_dlstnew.c \
                          ft_strtrim.c \
                          free_arr.c \
                          ft_lstdelone_bonus.c \
                          ft_strchr.c \
                          ft_bzero.c \
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

${NAME}:	${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} -o ${NAME} ${OBJS}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

all:		ar rc ${NAME}

bonus:		all

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re


