/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 03:44:14 by akharraz          #+#    #+#             */
/*   Updated: 2022/06/24 03:44:53 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	ft_atoi(char	*str)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		result = ((result * 10) + (str[i] - 48));
		if (result > INT_MAX)
			return (2147483648);
		i++;
	}
	return (result);
}

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
		usleep(200);
}
