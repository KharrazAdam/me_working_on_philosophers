# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 10:20:54 by akharraz          #+#    #+#              #
#    Updated: 2022/06/27 11:02:52 by akharraz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
HEADER = philo.h
SRC = philo.c analyse.c utils.c destroy_and_free.c

FLAGS = -Wall -Wextra -Werror

OFILES = ${SRC:%.c=%.o}

all: ${NAME}

${NAME}: ${OFILES} 
	$(CC) $(FLAGS) $(OFILES) -o $(NAME)

%.o : %.c ${HEADER}
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f ${NAME}

re: fclean all
