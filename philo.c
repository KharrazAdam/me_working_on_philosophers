/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:00:10 by akharraz          #+#    #+#             */
/*   Updated: 2022/06/05 23:25:20 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include "philo.h"
#include <limits.h>
void mon_init(char **av, t_info *philo)
{
	philo->number_of_philosophers = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		philo->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
}

void	*routine(void *lst)
{
	t_list *pv;
	pv = (t_list *)lst;
	while (pv)
	{
		printf("{{{%d}}}\n", pv->id);
		pv = pv->next;
		if (pv == NULL)
			pv = lst;
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
		pthread_create(&((*lst)->thread), NULL, routine, *lst);
		id++;
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
