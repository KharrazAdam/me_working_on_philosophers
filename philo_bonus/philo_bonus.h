/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 19:03:30 by akharraz          #+#    #+#             */
/*   Updated: 2022/06/27 15:10:11 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <fcntl.h>
# include <stdio.h>
# include <signal.h>

typedef struct s_info
{
	int				meals_n;
	int				id;
	long			mourir;
	long			dernier_diner;
	long			t_i;
	int				total_meals;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				last_param;
	pthread_t		check;
	pthread_t		num_p;
	sem_t			*forks;
	sem_t			*write_perm;
	sem_t			*num_meals;
	pid_t			pid;
	pid_t			*pids;
}	t_info;

int		mon_parsing(char **av);
int		mon_message(int num);
long	ft_atoi(char	*str);
long	ft_time(void);
void	sleep_time(long time);
void	routin(t_info *philo);
void	*check(void	*arg);
int		mon_init(char **av, t_info *philo);
void	creer_philo(t_info *philo);
void	ft_kill(t_info *data);
void	kill_all(t_info *data);
void	routin(t_info *philo);
void	*check(void	*arg);
#endif