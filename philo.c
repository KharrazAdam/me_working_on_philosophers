/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:00:10 by akharraz          #+#    #+#             */
/*   Updated: 2022/06/12 22:18:30 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include "philo.h"
#include <limits.h>

int	manger(t_list *lst, long daba)
{
	pthread_mutex_lock(&((lst)->fork));
	printf("%ld %d has taken a fork\n", ft_time() - daba, (lst)->id);
	pthread_mutex_lock(&((lst)->next->fork));
	printf("%ld %d has taken a fork\n", ft_time() - daba, (lst)->id);
	printf("%ld %d is eating\n",  ft_time() - daba , (lst)->id);
	lst->dernier_diner =  ft_time();
	lst->marat_li_9ssa_fihom++;
	if (lst->marat_li_9ssa_fihom == lst->info->number_of_times_each_philosopher_must_eat)
		lst->info->total_meals++;
	sleep_time(lst->info->time_to_eat);
	pthread_mutex_unlock(&((lst)->fork));
	pthread_mutex_unlock(&((lst)->next->fork));
	printf("%ld %d is sleeping\n", ft_time() - daba , (lst)->id);
	sleep_time(lst->info->time_to_sleep);
	printf("%ld %d is thinking\n", ft_time() - daba , (lst)->id);
	return (0);
}

int	mourir(t_list *lst)
{
	while ((lst))
	{
		lst->mourir =  ft_time() - lst->dernier_diner;
		if (lst->info->total_meals == lst->info->number_of_philosophers)
			return (0);
		(lst)->mourir = ft_time() - lst->dernier_diner;
		if ((lst)->mourir == (lst)->info->time_to_die)
			return(printf("%ld %d died\n", lst->mourir, lst->id), 0);
		(lst) = (lst)->next;
	}
	return (0);
}

void mon_init(char **av, t_info *philo)
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

void	*routine(void *lst)
{
	t_list 			*pv;
	struct timeval	dst;
	long			daba;

	pv = (t_list *)lst;
	if (pv->id % 2 != 0)
		usleep(50);
	daba = ft_time();
	while (1)
	{
		// (pv)->mourir = 0;
		manger(pv, daba);
	}
	return (NULL);	
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
	while(*lst)
	{
		pthread_create(&((*lst)->thread), NULL, &routine, *(lst));
		pthread_mutex_init(&((*lst)->fork), NULL);
		(*lst)->info = inf;
		(*lst)->dernier_diner = ft_time();
		*lst = (*lst)->next;
		if (new == (*lst))
			break;
	}	
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
		// while ((lst))
		// {
		// 	(lst)->mourir = temps((lst));
		// 	if ((lst)->mourir >= (lst)->info->time_to_die)
		// 		return (printf("%ld %d died\n", temps(lst), lst->id), 0);
		// 	(lst) = (lst)->next;
		// }
	}
	else
		return (mon_message(2));
	while (1);
	return (0);
}
