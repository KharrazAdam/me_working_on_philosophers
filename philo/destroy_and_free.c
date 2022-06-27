/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_and_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:33:28 by akharraz          #+#    #+#             */
/*   Updated: 2022/06/26 19:57:18 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

void	destroy_and_free(t_list *lst)
{
	int	i;

	i = -1;
	while (++i < lst->info->number_of_philosophers)
		(pthread_mutex_destroy(&lst->info->forks[i]));
	pthread_mutex_destroy(&lst->info->write_perm);
	free(lst->info->forks);
	free(lst->info);
	free(lst);
}
// destroy each fork;
// destroy write_perm;
// free(forks);
// free(info);
// free(lst);