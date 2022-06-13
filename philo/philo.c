/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:00:10 by akharraz          #+#    #+#             */
/*   Updated: 2022/06/13 06:16:11 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include "philo.h"
#include <limits.h>

int	manger(t_list *lst, long daba)
{
	pthread_mutex_lock(&((lst)->fork));
	pthread_mutex_lock(&((lst)->info->bach_yktbo));
	printf("%ld %d has taken a fork\n", ft_time() - daba, (lst)->id);
	pthread_mutex_unlock(&((lst)->info->bach_yktbo));
	pthread_mutex_lock(&((lst)->next->fork));
	pthread_mutex_lock(&((lst)->info->bach_yktbo));
	printf("%ld %d has taken a fork\n", ft_time() - daba, (lst)->id);
	printf("%ld %d is eating\n", ft_time() - daba, (lst)->id);
	pthread_mutex_unlock(&((lst)->info->bach_yktbo));
	lst->dernier_diner = ft_time();
	sleep_time(lst->info->time_to_eat);
	lst->marat_li_9ssa_fihom++;
	if (lst->marat_li_9ssa_fihom == \
	lst->info->number_of_times_each_philosopher_must_eat)
		lst->info->total_meals++;
	pthread_mutex_unlock(&((lst)->fork));
	pthread_mutex_unlock(&((lst)->next->fork));
	pthread_mutex_lock(&((lst)->info->bach_yktbo));
	printf("%ld %d is sleeping\n", ft_time() - daba, (lst)->id);
	pthread_mutex_unlock(&((lst)->info->bach_yktbo));
	sleep_time(lst->info->time_to_sleep);
	pthread_mutex_lock(&((lst)->info->bach_yktbo));
	printf("%ld %d is thinking\n", ft_time() - daba, (lst)->id);
	pthread_mutex_unlock(&((lst)->info->bach_yktbo));
	return (0);
}

int	mourir(t_list *lst)
{
	while ((lst))
	{
		lst->mourir = ft_time() - lst->dernier_diner;
		if (lst->info->total_meals == lst->info->number_of_philosophers)
			return (0);
		(lst)->mourir = ft_time() - lst->dernier_diner;
		if ((lst)->mourir == (lst)->info->time_to_die)
		{
			pthread_mutex_lock(&lst->info->bach_yktbo);
			return (printf("%ld %d died\n", lst->mourir, lst->id), 0);
		}
		(lst) = (lst)->next;
	}
	return (0);
}

void	*routine(void *lst)
{
	t_list			*pv;
	long			daba;

	pv = (t_list *)lst;
	if (pv->id % 2 != 0)
		usleep(50);
	daba = ft_time();
	while (1)
		manger(pv, daba);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_info		philo;
	t_list		*lst;

	lst = NULL;
	if (ac >= 5 && ac <= 6)
	{
		if (!mon_parsing(av))
			return (-1);
		mon_init(av, &philo);
		creer_philos(&lst, &philo);
		if (!mourir(lst))
			return (-1);
	}
	else
		return (mon_message(2));
	while (1)
		;
	return (0);
}
