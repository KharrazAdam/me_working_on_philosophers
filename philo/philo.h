/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:02:37 by akharraz          #+#    #+#             */
/*   Updated: 2022/06/13 06:05:40 by akharraz         ###   ########.fr       */
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
	int				total_meals;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	long			temps_init;
	pthread_mutex_t	bach_yktbo;
}	t_info;

typedef struct s_list
{
	int				marat_li_9ssa_fihom;
	int				id;
	long			mourir;
	long			dernier_diner;
	pthread_t		thread;
	pthread_mutex_t	fork;
	struct s_list	*next;
	t_info			*info;
}	t_list;

long	ft_atoi(char	*str);
int		mon_message(int num);
int		mon_est_entiers(char *str);
int		mon_parsing(char **av);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	ft_lstclear(t_list **lst);
int		mon_est_entiers(char *str);
long	ft_time(void);
void	sleep_time(long time);

#endif