/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:00:10 by akharraz          #+#    #+#             */
/*   Updated: 2022/06/12 05:11:50 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include "philo.h"
#include <limits.h>

// void	sleep_time(long time)
// {
// 	long	current_time;

// 	current_time = temps(lst);
// 	while ((ft_time() - current_time) < time)
// 		usleep(100);
// }

int	manger(t_list *lst)
{
	printf("%ld %d has taken a fork\n", temps((lst)), (lst)->id);
	pthread_mutex_lock(&((lst)->fork));
	printf("%ld %d has taken a fork\n", temps((lst)), (lst)->id);
	printf("%ld %d is eating\n", temps((lst)), (lst)->id);
	lst->marat_li_9ssa_fihom++;
	if (lst->marat_li_9ssa_fihom == lst->info->must_eat)
		lst->info->total_meals++;
	pthread_mutex_lock(&((lst)->next->fork));
	// usleep((lst)->info->time_to_eat * 1000);
	lst->dernier_diner = temps();
	sleep_time((lst)->info->time_to_eat);
	// lst->dernier_diner = temps(lst);
	pthread_mutex_unlock(&((lst)->fork));
	printf("%ld %d is sleeping\n", temps((lst)), (lst)->id);
	pthread_mutex_unlock(&((lst)->next->fork));
	sleep_time((lst)->info->time_to_sleep);
	printf("%ld %d is thinking\n", temps((lst)), (lst)->id);
	// usleep((lst)->info->time_to_sleep * 1000);
	return (0);
}

int	mourir(t_list *lst)
{
	while ((lst))
	{
		if (lst->info->total_meals == lst->info->number_of_philosophers)
			return (0);
		(lst)->mourir = temps() - lst->dernier_diner;
		if ((lst)->mourir >= (lst)->info->time_to_die)
			return (printf("%ld %d died\n", temps(), lst->id), 0);
		(lst) = (lst)->next;
	}
	return (0);
}

void	mon_init(char **av, t_info *philo)
{
	struct timeval	temp;

	philo->number_of_philosophers = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	philo->total_meals = 0;
	if (av[5])
		philo->must_eat = ft_atoi(av[5]);
	gettimeofday(&temp, NULL);
	philo->temps_init = (temp.tv_sec * 1000) + (temp.tv_usec / 1000);
}

void	*routine(void *lst)
{
	t_list			*pv;
	struct timeval	dst;

	pv = (t_list *)lst;
	pv->marat_li_9ssa_fihom = 0;
	if (pv->id % 2 != 0)
		usleep(40);
	while (1)
		manger(pv);
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
	while (*lst)
	{
		pthread_create(&((*lst)->thread), NULL, &routine, *(lst));
		pthread_mutex_init(&((*lst)->fork), NULL);
		(*lst)->info = inf;
		*lst = (*lst)->next;
		if (new == (*lst))
			break ;
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
	}
	else
		return (mon_message(2));
	while (1)
		;
	return (0);
}
