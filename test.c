/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:50:07 by akharraz          #+#    #+#             */
/*   Updated: 2022/06/05 23:26:41 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

// void    my_turn(void)
// {
// 	while(1) 
// 	{
// 		printf("my_turn\n");
// 		sleep(1);
// 	}
// }

// void    *your_turn(void *arg)
// {
// 	arg = NULL;
// 	while (1)
// 	{
// 		printf("your turn\n");
// 		sleep(1);
// 	}
// 	return (arg);
// }

// // void *other_turn(void *arg)
// // {
// // 	arg = NULL;
// // 	while (42)
// // 	{
// // 		printf("other_turn\n");
// // 		sleep(1);
// // 	}
// // 	return (arg);
// // }
// int main()
// {
// 	pthread_t pt;
// 	pthread_t pt1;
// 	pthread_create(&pt, NULL, your_turn, NULL);
// 	// pthread_create(&pt1, NULL, &other_turn, NULL);
// 	my_turn();
// }

int main(int ac, char **arg)
{
    
}