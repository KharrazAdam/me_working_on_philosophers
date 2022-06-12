/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 04:13:52 by akharraz          #+#    #+#             */
/*   Updated: 2022/06/12 05:03:43 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <sys/time.h>

long	temps(void)
{
	struct timeval	dst;

	gettimeofday(&dst, NULL);
	return (((dst.tv_sec * 1000) + (dst.tv_usec / 1000)));
}

void	sleep_time(long time)
{
	long	current_time;

	current_time = temps();
	while ((temps() - current_time) < time)
		usleep(100);
}