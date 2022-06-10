/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:50:07 by akharraz          #+#    #+#             */
/*   Updated: 2022/06/09 10:38:58 by akharraz         ###   ########.fr       */
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
// void *your_turn(void *arg)
// {
// 	arg = NULL; 
// 	int i = 0;
// 	while (1)
// 	{
// 		printf ("hello %d\n", i);
// 		i++;
// 		sleep(1);
// 	}
// 	return arg;
// }

// int main(int ac, char **arg)
// {
// 	pthread_t m1;
// 	pthread_t m2;
// 	pthread_t m3;

// 	pthread_create(&m1, NULL, your_turn, NULL);
// 	pthread_create(&m2, NULL, your_turn, NULL);
// 	pthread_create(&m3, NULL, your_turn, NULL);
// 	while (1);
// }

int main()
{
	int i = 0;
	while (1)
	{	
		printf("%d allo\n", i);
		sleep(1);
		i++;
	}
	return 0;
}