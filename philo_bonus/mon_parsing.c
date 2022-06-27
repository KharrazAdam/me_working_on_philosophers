/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mon_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 19:02:14 by akharraz          #+#    #+#             */
/*   Updated: 2022/06/27 15:13:44 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "philo_bonus.h"

int	mon_message(int num)
{
	write (2, "error\n", 6);
	if (num == 0)
		write(2, "veuillez inserer un nombre positif\n", 35);
	else if (num == 1)
		write(2, "veuillez inserer un chiffre\n", 28);
	else if (num == 2)
		write(2, "veuillez inserer 4 ou 5 inputs\n", 31);
	else if (num == 3)
		write(2, "vide argument !\n", 16);
	else if (num == 4)
		write(2, "veuillez inserer un chiffre reasonable!\n", 40);
	return (0);
}

int	mon_est_entiers(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (mon_message(3));
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
		return (mon_message(0));
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (mon_message(1));
		i++;
	}
	if (ft_atoi(str) == 2147483648)
		return (mon_message(4));
	return (1);
}

int	mon_parsing(char **av)
{
	int	i;

	i = 0;
	while (av[++i])
	{
		if (!mon_est_entiers(av[i]) || ft_atoi(av[1]) == 0)
			return (printf("this value can't be 0!!\n"), 0);
		if (av[5])
			if (ft_atoi(av[5]) == 0)
				return (0);
	}
	return (1);
}

int	mon_init(char **av, t_info *philo)
{
	philo->number_of_philosophers = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		philo->last_param = ft_atoi(av[5]);
	philo->total_meals = 0;
	philo->meals_n = 0;
	if (sem_unlink("forks"))
		return (0);
	philo->forks = sem_open("forks", O_CREAT, \
	666, philo->number_of_philosophers);
	if (sem_unlink("write_perm"))
		return (0);
	philo->write_perm = sem_open("write_perm", O_CREAT, 666, 1);
	if (sem_unlink("num_meals"))
		return (0);
	philo->num_meals = sem_open("num_meals", O_CREAT, 666, 0);
	philo->dernier_diner = ft_time();
	return (1);
}
