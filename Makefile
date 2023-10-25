CC			= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS		= push_swap.c \
					utils_1.c \
					utils_2.c \
					utils_3.c \
					utils_4.c \
					utils_5.c \
					utils_for_zsh_1.c \
					utils_for_zsh_2.c \
					utils_operation_1.c \
					utils_operation_2.c

OBJS		= $(SRCS:.c=.o)
HEADER	= push_swap.h
NAME		= push_swap

all:			$(NAME)

$(NAME):	$(OBJS)
					$(CC) $(FLAGS) $(SRCS) -o $(NAME)

%.o:			%.c $(HEADER)
					$(CC) $(CFLAGS) -c $< -o $@

clean:
					rm -f $(OBJS)

fclean:		clean
					rm -f $(NAME)

re:				fclean all

.PHONY:		all clean fclean re