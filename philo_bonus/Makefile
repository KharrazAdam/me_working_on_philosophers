# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 10:20:49 by akharraz          #+#    #+#              #
#    Updated: 2022/06/13 10:28:15 by akharraz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

SRC = philo_bonus.c analyse_bonus.c ft_lst_func_bonus.c utils_bonus.c

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
