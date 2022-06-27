/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 09:02:15 by akharraz          #+#    #+#             */
/*   Updated: 2022/06/25 08:04:50 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_kill(t_info *philo)
{
	int	i;

	i = 0;
	while (i < philo->number_of_philosophers)
	{
		kill(philo->pids[i], SIGKILL);
		i++;
	}
}

void	kill_all(t_info *philo)
{
	int		i;
	pid_t	pid;

	i = 1;
	while (1)
	{
		pid = waitpid(-1, &i, 0);
		if (i == 0 || pid == -1)
		{
			ft_kill(philo);
			free(philo->pids);
			sem_close(philo->forks);
			sem_close(philo->write_perm);
			break ;
		}
	}
}
