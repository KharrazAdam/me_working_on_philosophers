/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:00:10 by akharraz          #+#    #+#             */
/*   Updated: 2022/06/29 12:28:44 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include "philo.h"
#include <limits.h>

void	manger_2(t_list *lst, long now)
{
	pthread_mutex_unlock(&((lst)->info->write_perm));
	if (lst->id == lst->info->number_of_philosophers)
		pthread_mutex_lock(&((lst)->info->forks[0]));
	else
		pthread_mutex_lock(&((lst)->info->forks[lst->id]));
	pthread_mutex_lock(&((lst)->info->write_perm));
	printf("%ld %d has taken a fork\n", ft_time() - now, (lst)->id);
	printf("%ld %d is eating\n", ft_time() - now, (lst)->id);
	lst->dernier_diner = ft_time();
	pthread_mutex_unlock(&((lst)->info->write_perm));
	sleep_time(lst->info->time_to_eat);
	lst->many_meals++;
	if (lst->many_meals == lst->info->number_of_times_each_philosopher_must_eat)
	{
		pthread_mutex_lock(&((lst)->info->write_perm));
		lst->info->total_meals++;
		pthread_mutex_unlock(&((lst)->info->write_perm));
	}
	pthread_mutex_unlock(&((lst)->info->forks[lst->id - 1]));
	if (lst->id == lst->info->number_of_philosophers)
		pthread_mutex_unlock(&((lst)->info->forks[0]));
	else
		pthread_mutex_unlock(&((lst)->info->forks[lst->id]));
}

int	manger(t_list *lst, long now)
{
	pthread_mutex_lock(&((lst)->info->forks[lst->id - 1]));
	pthread_mutex_lock(&((lst)->info->write_perm));
	printf("%ld %d has taken a fork\n", ft_time() - now, (lst)->id);
	manger_2(lst, now);
	pthread_mutex_lock(&((lst)->info->write_perm));
	printf("%ld %d is sleeping\n", ft_time() - now, (lst)->id);
	pthread_mutex_unlock(&((lst)->info->write_perm));
	sleep_time(lst->info->time_to_sleep);
	pthread_mutex_lock(&((lst)->info->write_perm));
	printf("%ld %d is thinking\n", ft_time() - now, (lst)->id);
	pthread_mutex_unlock(&((lst)->info->write_perm));
	return (0);
}

int	mourir(t_list *lst)
{
	int	i;

	i = 0;
	while (1)
	{
		if (lst[i].info->total_meals >= lst[i].info->number_of_philosophers)
		{
			pthread_mutex_lock(&lst[i].info->write_perm);
			return (0);
		}
		(lst)->mourir = ft_time() - lst[i].dernier_diner;
		if ((lst)->mourir >= (lst)->info->time_to_die)
		{
			pthread_mutex_lock(&lst[i].info->write_perm);
			return (printf("%ld %d died\n", ft_time() - lst->info->temps_init, \
					lst[i].id), 0);
		}
		if (i == lst->info->number_of_philosophers - 1)
			i = 0;
		else
			i++;
	}
	return (0);
}

void	*routine(void *lst)
{
	t_list			*pv;
	long			now;

	pv = (t_list *)lst;
	if (pv->id % 2 != 0)
		usleep(250);
	now = ft_time();
	while (1)
		manger(pv, now);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_info		*philo;
	t_list		*lst;

	lst = NULL;
	philo = NULL;
	if (ac >= 5 && ac <= 6)
	{
		philo = malloc(sizeof(t_info));
		if (!philo)
			return (printf("t_info *philo : failed memory allocation\n"), -1);
		if (!mon_parsing(av))
			return (free(philo), -1);
		mon_init(av, philo);
		lst = malloc(philo->number_of_philosophers * sizeof(t_list));
		if (!lst)
			return (free(philo), printf("t_list *lst; : \
					failed memory allocation\n"), -1);
		if (!creer_philos(lst, philo))
			return (destroy_and_free(lst), -1);
		if (!mourir(lst))
			return (destroy_and_free(lst), -1);
	}
	else
		return (mon_message(2));
	return (0);
}
