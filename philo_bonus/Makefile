# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/18 19:00:51 by akharraz          #+#    #+#              #
#    Updated: 2022/06/25 08:06:24 by akharraz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus
HEADER = philo_bonus.h
SRC = philo_bonus.c mon_parsing.c utils.c kill_p.c main.c

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
