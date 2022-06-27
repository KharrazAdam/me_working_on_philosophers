/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:28:33 by akharraz          #+#    #+#             */
/*   Updated: 2022/06/27 15:17:17 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_info		philo;

	if (ac >= 5 && ac <= 6)
	{
		if (!mon_parsing(av) || !mon_init(av, &philo))
			return (-1);
		creer_philo(&philo);
	}
	else
		return (mon_message(2));
	return (0);
}
