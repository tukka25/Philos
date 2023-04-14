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
	$(CC) $(CFLAGS) $(OBJS) -o -pthread -o $(NAME)
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all