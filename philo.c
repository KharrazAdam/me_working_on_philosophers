/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:00:10 by akharraz          #+#    #+#             */
/*   Updated: 2022/06/08 08:37:41 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include "philo.h"
#include <limits.h>
int mangeant(t_list *lst)
{
	printf("philo's id = %d is eating at %ld\n",);	
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
	long			temps;

	pv = (t_list *)lst;
	while (1)
	{
		gettimeofday(&dst, NULL);
		temps = ((dst.tv_sec * 1000) + (dst.tv_usec / 1000)) - pv->info->temps_init;
		printf("il est %ld bonjour de philo %d \n", temps, pv->id);
		usleep(100000);
	}
	return (NULL);	
}

void	creer_philos(t_list **lst, t_info *inf)
{
	int		id;
	t_list	*new;

	id = 0;
	while (id < inf->number_of_philosophers)
	{
		new = ft_lstnew(id);
		ft_lstadd_back(lst, new);
		id++;
	}
	while(*lst)
	{
		pthread_create(&((*lst)->thread), NULL, &routine, *(lst));
		(*lst)->info = inf;
		*lst = (*lst)->next;
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
	}
	else
		return (mon_message(2));
	while (1);
	return (0);
}
