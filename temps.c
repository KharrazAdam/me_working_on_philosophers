/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 04:13:52 by akharraz          #+#    #+#             */
/*   Updated: 2022/06/10 14:51:27 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <sys/time.h>

// int main()
// {
// 	long daba = (dst.tv_sec * 1000) + (dst.tv_usec / 1000);
// 	printf("%ld\n", daba);
// 	sleep(1);
// 	gettimeofday(&dst, NULL);
// 	long daba_xwia =  - daba;
// 	printf("%ld\n", daba_xwia);
// }

long temps(t_list *lst)
{
	struct timeval	dst;

	gettimeofday(&dst, NULL);
	return (((dst.tv_sec * 1000) + (dst.tv_usec / 1000)) - lst->info->temps_init);
}