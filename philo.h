/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:02:37 by akharraz          #+#    #+#             */
/*   Updated: 2022/06/08 02:04:41 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
typedef struct s_info
{
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_times_each_philosopher_must_eat;
	long	temps_init;
}	t_info;

typedef struct s_list
{
	pthread_t	thread;
	int		id;
	pthread_mutex_t	fork;
	struct s_list *next;
	t_info	*info;
}	t_list;

//-----partie--analyse----------
long	ft_atoi(char	*str);
int		mon_message(int num);
int		mon_est_entiers(char *str);
int		mon_parsing(char **av);

//----liste--chainée------------
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);

int		mon_est_entiers(char *str);

#endif