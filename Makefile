NAME = philo

SRCS =	philo.c         \
		parsing.c       \
		utils.c         \
		routine.c       \
		threads.c       \
		utils2.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS =  -g -Wall -Wextra -Werror -fsanitize=address

all:$(NAME)

$(NAME):$(OBJS) 
	@make -C ./libft
	$(CC) $(CFLAGS) $(OBJS) -o -pthread -o $(NAME)
clean:
	rm -f $(OBJS)
	rm -f ./libft/*.o

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all