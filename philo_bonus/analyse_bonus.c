/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:26:12 by akharraz          #+#    #+#             */
/*   Updated: 2022/06/13 10:26:24 by akharraz         ###   ########.fr       */
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
		if (!mon_est_entiers(av[i]))
			return (0);
		if (av[5])
			if (ft_atoi(av[5]) == 0)
				return (0);
	}
	return (1);
}
