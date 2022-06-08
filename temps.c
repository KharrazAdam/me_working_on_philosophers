/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 04:13:52 by akharraz          #+#    #+#             */
/*   Updated: 2022/06/07 21:03:14 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <sys/time.h>

int main()
{
	struct timeval	dst;
	gettimeofday(&dst, NULL);
	long daba = (dst.tv_sec * 1000) + (dst.tv_usec / 1000);
	printf("%ld\n", daba);
	sleep(1);
	gettimeofday(&dst, NULL);
	long daba_xwia = ((dst.tv_sec * 1000) + (dst.tv_usec / 1000)) - daba;
	printf("%ld\n", daba_xwia);
}