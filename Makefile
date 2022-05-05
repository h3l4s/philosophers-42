NAME = philo

SRCS = ./src/philo.c ./src/parsing.c ./src/init.c ./src/philo_actions.c ./src/eat.c ./src/think.c ./src/sleep.c ./src/check_death.c ./src/exit.c ./src/utils_1.c ./src/utils_2.c ./src/utils_3.c

OBJS = $(SRCS:.c=.o)

UNAME_S := $(shell uname -s)
   ifeq ($(UNAME_S),Linux)
        CC=clang-9
    endif
    ifeq ($(UNAME_S),Darwin)
        CC=clang
    endif

CFLAGS = -Wall -Wextra -Werror -pthread

INCLUDES= -I includes/

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all
