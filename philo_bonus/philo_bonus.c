/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:58:51 by akharraz          #+#    #+#             */
/*   Updated: 2022/06/27 18:12:41 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eating(t_info *philo)
{
	sem_wait(philo->write_perm);
	printf("%ld %d is eating\n", ft_time() - philo->t_i, philo->id);
	philo->meals_n++;
	if (philo->meals_n == philo->last_param)
		sem_post(philo->num_meals);
	philo->dernier_diner = ft_time();
	sem_post(philo->write_perm);
	sleep_time(philo->time_to_eat);
	sem_post(philo->forks);
	sem_post(philo->forks);
}

void	routin(t_info *philo)
{
	while (1)
	{
		sem_wait(philo->write_perm);
		printf("%ld %d is thinking\n", ft_time() - philo->t_i, philo->id);
		sem_post(philo->write_perm);
		sem_wait(philo->forks);
		sem_wait(philo->write_perm);
		printf("%ld %d has taken a fork\n", ft_time() - philo->t_i, philo->id);
		sem_post(philo->write_perm);
		sem_wait(philo->forks);
		sem_wait(philo->write_perm);
		printf("%ld %d has taken a fork\n", ft_time() - philo->t_i, philo->id);
		sem_post(philo->write_perm);
		eating(philo);
		sem_wait(philo->write_perm);
		printf("%ld %d is sleeping\n", ft_time() - philo->t_i, philo->id);
		sem_post(philo->write_perm);
		sleep_time(philo->time_to_sleep);
	}
}

void	*num_p(void	*arg)
{
	t_info			*philo;
	int				i;

	i = -1;
	philo = (t_info *)arg;
	while (1)
	{
		i++;
		if (i == philo->number_of_philosophers)
		{
			sem_close(philo->num_meals);
			ft_kill(philo);
			exit(0);
		}
		else
			sem_wait(philo->num_meals);
	}
}

void	*check(void	*arg)
{
	t_info			*philo;

	philo = (t_info *)arg;
	while (1)
	{
		if (ft_time() - philo->dernier_diner >= (long)philo->time_to_die)
		{
			sem_wait(philo->write_perm);
			printf("%ld %d died\n", ft_time() - philo->dernier_diner, philo->id);
			exit(0);
		}
	}
}

void	creer_philo(t_info *philo)
{
	int		id;
	pid_t	pid;

	pid = 1;
	id = -1;
	philo->pids = malloc(philo->number_of_philosophers * sizeof(pid_t));
		if (!philo->pids)
			return ;
	philo->t_i = ft_time();
	while (id++ < philo->number_of_philosophers - 1 && pid != 0)
	{
		pid = fork();
		if (pid == -1)
		{
			ft_kill(philo);
			free(philo->pids);
			return ;
		}
		philo->id = id + 1;
		philo->pids[id] = pid;
		if (pid == 0)
		{
			pthread_create(&(philo->check), NULL, &check, philo);
			routin(philo);
		}
	}
	if (pid != 0)
	{
		pthread_create(&(philo->num_p), NULL, &num_p, philo);
		kill_all(philo);
	}
}
