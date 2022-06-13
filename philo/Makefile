NAME = philo

SRC = philo.c analyse.c ft_lst_func.c utils.c

FLAGS = -Wall -Wextra -Werror

OFILES = ${SRC:%.c=%.o}

all: ${NAME}	

${NAME}: ${OFILES}
	$(CC) $(FLAGS) $(OFILES) -o $(NAME)

%.o : %.c 
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f ${NAME}

re: fclean all
