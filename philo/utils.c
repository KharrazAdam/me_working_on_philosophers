/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 04:13:52 by akharraz          #+#    #+#             */
/*   Updated: 2022/06/27 13:07:30 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <sys/time.h>

long	ft_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	sleep_time(long time)
{
	long	current_time;

	current_time = ft_time();
	while ((ft_time() - current_time) < time)
		usleep(100);
}

void	mon_init(char **av, t_info *philo)
{
	struct timeval	temp;
	int				i;

	i = -1;
	philo->total_meals = 0;
	philo->number_of_philosophers = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		philo->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
	gettimeofday(&temp, NULL);
	philo->temps_init = (temp.tv_sec * 1000) + (temp.tv_usec / 1000);
	pthread_mutex_init(&(philo->write_perm), NULL);
	pthread_mutex_init(&(philo->die), NULL);
	philo->forks = malloc(philo->number_of_philosophers \
	* sizeof(pthread_mutex_t));
	while (++i < philo->number_of_philosophers)
		pthread_mutex_init(&(philo->forks[i]), NULL);
}

int	creer_philos(t_list *lst, t_info *inf)
{
	int		id;
	int		i;

	id = 1;
	i = 0;
	while (i < inf->number_of_philosophers)
	{
		lst[i].id = id;
		lst[i].many_meals = 0;
		id++;
		i++;
	}
	i = 0;
	while (i < inf->number_of_philosophers)
	{
		lst[i].info = inf;
		lst[i].dernier_diner = ft_time();
		if (pthread_create(&(lst[i].thread), NULL, &routine, &lst[i]) != 0)
			return (0);
		i++;
	}
	return (1);
}
