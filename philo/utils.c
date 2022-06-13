/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 04:13:52 by akharraz          #+#    #+#             */
/*   Updated: 2022/06/13 09:15:49 by akharraz         ###   ########.fr       */
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

	philo->number_of_philosophers = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		philo->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
	gettimeofday(&temp, NULL);
	philo->temps_init = (temp.tv_sec * 1000) + (temp.tv_usec / 1000);
}

void	creer_philos(t_list **lst, t_info *inf)
{
	int		id;
	t_list	*new;
	t_list	*pv;

	id = 1;
	while (id <= inf->number_of_philosophers)
	{
		new = ft_lstnew(id);
		ft_lstadd_back(lst, new);
		id++;
	}
	new = *lst;
	pv = *lst;
	pthread_mutex_init(&(inf->bach_yktbo), NULL);
	while (*lst)
	{
		pthread_create(&((*lst)->thread), NULL, &routine, *(lst));
		pthread_mutex_init(&((*lst)->fork), NULL);
		(*lst)->info = inf;
		(*lst)->dernier_diner = ft_time();
		*lst = (*lst)->next;
		if (new == (*lst))
			break ;
	}
}
