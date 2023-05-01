NAME = philo

SRCS =	philo.c         \
		parsing.c       \
		utils.c         \
		routine.c       \
		threads.c       \
		utils2.c        \
		routine_utils.c \
		destory.c       \
		life_cycle.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS =  -g3 -Wall -Wextra -Werror -pthread

all:$(NAME)

$(NAME):$(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all